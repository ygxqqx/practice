#ifndef _THREADPOOL_H
#define _THREADPOOL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdint.h>
#include "dbg.h"

#define THREAD_NUM 8

typedef struct yg_task_s {
    void (*func)(void *);
    void *arg;
    struct yg_task_s *next;
} yg_task_t;

typedef struct {
    pthread_mutex_t lock;
    pthread_cond_t cond;
    pthread_t *threads;
    yg_task_t *head;
    int thread_count;
    int queue_size;
    int shutdown;
    int started;
} yg_threadpool_t;

typedef enum {
    yg_tp_invalid   = -1,
    yg_tp_lock_fail = -2,
    yg_tp_already_shutdown  = -3,
    yg_tp_cond_broadcast    = -4,
    yg_tp_thread_fail       = -5,
    
} yg_threadpool_error_t;

yg_threadpool_t *threadpool_init(int thread_num);

int threadpool_add(yg_threadpool_t *pool, void (*func)(void *), void *arg);

int threadpool_destroy(yg_threadpool_t *pool, int gracegul);

#ifdef __cplusplus
}
#endif

#endif
