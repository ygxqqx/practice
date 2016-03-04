#ifndef _DBG_H
#define _DBG_H

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#ifdef NDEBUG
#define deBug(M, ...)
#else
#define deBug(M, ...) fprintf(stderr,"DEBUG %s:%d:" M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif

#define cleanErrno() (errno == 0 ? "None" :strerror(errno))

#define logErr(M, ...) fprintf(stderr, "[ERROR] (%s:%d: errno: %s)" M "\n",__FILE__,__LINE__,cleanErrno(), ##__VA_ARGS__)

#define logWarn(M, ...) fprintf(stderr,"[WARN] (%s:%d: warn: %s)" M "\n",__FILE__,__LINE__,cleanErrno(), ##__VA_ARGS__)

#define logInfo(M, ...) fprintf(stderr, "[INFO](%s : %d)" M "\n",__FILE__,__LINE__, ##__VA_ARGS__)

#define check(A, M, ...) if(!(A)) {logErr(M, ##__VA_ARGS__); exit(1);}

#define checkDebug(A, M, ...) if(!(A)) {debug(M, ##__VA_ARGS__); exit(1);}

#endif
