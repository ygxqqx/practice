#include "threadpool.h"


void hand(void *arg){
	int n = (int)(arg);
	unsigned long sum = 0, i;

	for(i=0; i<n; ++i){
		sum += i;
	}
	printf("thread %lu complet sum %d: %lu\n", (unsigned long)pthread_self(), n, sum);
}


int main(){

	threadpool_t *pool = threadpool_init(8);
	if(pool)
		printf("pool init successful thread start:%d\n", pool->thread_start);
	int i;
	for(i=0; i<10000; ++i){
		// printf("read sum %d\n", i);
		if(threadpool_add(pool, hand, (void *)i) == -1){
			printf("pthread add err===========\n");
		}
	}
	
	threadpool_destroy(pool, 1);
	return 0;
}