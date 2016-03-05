#include "threadpool.h"


void handler(void *arg){
	int n = (int)(*arg);
	unsigned long sum = 0, i;

	for(i=0; i<n; ++i){
		sum += i;
	}
	printf("thread %lu complet sum %d: %lu\n", (unsigned long)pthread_self(), n, sum);
}


int main(){

	threadpool_t *pool = threadpool_init(4);
	int i;
	for(i=0; i<10000; ++i){
		threadpool_add(pool, handler, (void *)i);
	}
	
	threadpool_destroy(pool, 1);
	return 0;
}