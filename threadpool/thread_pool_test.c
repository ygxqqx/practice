#include "threadpool.h"

#define THREAD_NUM 8

static void sum_n(void *arg) {
    int n = (int) arg;
    unsigned long sum = 0, i;
    for (i=0; i<n; i++) {
        sum += i;
    }
    
    logInfo("thread %08x complete sum %d: %lu", pthread_self(), n, sum);
}

int main() {
    int rc;
    yg_threadpool_t *tp = threadpool_init(THREAD_NUM);
    
    int i;
    for (i=0; i< 100; i++){
        logInfo("ready to add num %d", i);
        rc = threadpool_add(tp, sum_n, (void *)i);
        check(rc == 0, "rc == 0");
    }

    if (threadpool_destroy(tp, 1) < 0) {
        logErr("destroy threadpool failed");
    }
    return 0;
}
