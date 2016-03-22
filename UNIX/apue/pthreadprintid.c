#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

void printId(char *c){
    pid_t pid;
    pthread_t tid;
    pid = getpid();
    tid = pthread_self();

    printf("%s:pid = %lu, tid = %lu \n", c, (unsigned long)pid, (unsigned long)tid);
}

void *thr_fn(void *arg){
    printId(arg);
    return ((void *)0);
}


int main(){

    pthread_t tid;
    pthread_create(&tid, NULL, thr_fn, "new thread");
    printId("main thread");
    // sleep(1);
    pthread_join(tid,NULL);
    return 0;
}