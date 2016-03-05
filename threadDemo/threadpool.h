#ifndef _THREAD_POOL
#define _THREAD_POOL

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define SHUTDOWNNOW 0
#define GRACEFULSHUTDOWN 1


typedef struct thread_task{
	void (*func)(void*);
	struct thread_task *next;
	void *arg;
}thread_task;

typedef struct threadpool_t{
	pthread_t *threads;
	int thread_count;//线程数
	int thread_start;
	int quequ_size;
	int shutdown;
	pthread_mutex_t mutex;
	pthread_cond_t cond;
	thread_task *head;

}threadpool_t;


threadpool_t *threadpool_init(int num);

int threadpool_add(threadpool_t *pool, void (*handler)(void *),void *arg);

int threadpool_destroy(threadpool_t *pool, int graceful);

#endif