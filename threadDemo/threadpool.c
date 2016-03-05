#include "threadpool.h"


void *handler(void *arg){
	if(!arg)
		return NULL;
	threadpool_t *pool = (threadpool_t *)arg;

	thread_task* p;
	while(1){
		pthread_mutex_lock(&(pool->mutex));
		while(pool->quequ_size <= 0 && (pool->shutdown == GRACEFULSHUTDOWN))
			pthread_cond_wait(&(pool->cond), &(pool->mutex));
		if(pool->shutdown == SHUTDOWNNOW){
			break;
		}
		else if(pool->shutdown == GRACEFULSHUTDOWN && pool->quequ_size <= 0){
			break;
		}
		p = pool->head->next;
		if(p == NULL){
			pthread_mutex_unlock(&(pool->mutex));
			continue;
		}
		pool->head->next = p->next;
		pool->quequ_size--;
		pthread_mutex_unlock(&(pool->mutex));
		(*(p->func))(p->arg);
		free(p);
	}
	pool->thread_start--;
	pthread_mutex_unlock(&(pool->mutex));
	pthread_exit(NULL);
	return NULL;
}


threadpool_t *threadpool_init(int num){

	if(num <= 0){
		printf("num < = 0 error:\n");
		return NULL;
	}
	threadpool_t *pool;
	if((pool = (threadpool_t *)malloc(sizeof(threadpool_t))) == NULL)
		return NULL;

	// pool->thread_count = num;
	pool->quequ_size = 0;
	pool->thread_count = 0;
	pool->thread_start = 0;
	pool->shutdown = GRACEFULSHUTDOWN;
	pool->head = (thread_task *)malloc(sizeof(thread_task));
	pool->threads = (pthread_t *)malloc(sizeof(pthread_t) * num);
	if((pool->head) == NULL || (pool->threads) == NULL){
		goto err;
	}
	pool->head->next = NULL;
	pool->head->func = NULL;
	pthread_cond_init(&(pool->cond), NULL);
	if(pthread_mutex_init(&(pool->mutex), NULL) != 0){
		pthread_cond_destroy(&(pool->cond));
		goto err;
	}

	int i;
	for(i=0; i < num; ++i){
		if(pthread_create(&(pool->threads[i]), NULL, handler, (void *)pool) != 0){
			threadpool_destroy(pool, SHUTDOWNNOW);
			return NULL;		
		}
		pool->thread_count++;
		pool->thread_start++;
	}

	return pool;
err:
	if(pool)
		threadpool_free(pool);
	return NULL;
}


int threadpool_add(threadpool_t *pool, void (*handler)(void *),void *arg){
	int err = 0;
	if(pool == NULL || handler == NULL || arg == NULL)
		return -1;
	pthread_mutex_lock(&(pool->mutex));
	if(pool->shutdown == SHUTDOWNNOW){
		pthread_mutex_unlock(&(pool->mutex));
		return err;
	}
	thread_task *task;
	if((task = (thread_task *)malloc(sizeof(thread_task))) == NULL){
		pthread_mutex_unlock(&(pool->mutex));
		return -1;
	}
	task->arg = arg;
	task->func = handler;

	task->next = pool->head->next;
	pool->head->next = task;
	pool->quequ_size++;
	pthread_mutex_unlock(&(pool->mutex));

	pthread_cond_signal(&(pool->cond));
	return err;
}

int threadpool_free(threadpool_t *pool){

	if(pool == NULL)
		return -1;
	if(pool->threads)
		free(pool->threads);

	thread_task *p;
	while(pool->head->next){
		p = pool->head->next;
		pool->head->next = p->next;
		free(p);
	}

	return 0;
}


int threadpool_destroy(threadpool_t *pool, int graceful){
	int err = 0;

	if(pool == NULL)
		return -1;
	if(pthread_mutex_lock(&(pool->mutex)) != 0)
		return -1;
	do{
		if(pool->shutdown){

			break;
		}
		pool->shutdown = (graceful > 0)?GRACEFULSHUTDOWN:SHUTDOWNNOW;
		if(pthread_cond_broadcast(&(pool->cond)) != 0){
			break;
		}
		if(pthread_mutex_unlock(&(pool->mutex)) != 0){
			break;
		}
		int i;
		for(i=0; i < pool->thread_count; ++i){
			if(pthread_join(pool->threads[i], NULL) != 0){
				break;
			}
		}
			
	}while(0);

	pthread_mutex_destroy(&(pool->mutex));
	pthread_cond_destroy(&(pool->cond));
	threadpool_free(pool);

	return err;
}