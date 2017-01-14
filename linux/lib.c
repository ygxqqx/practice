#include "lib.h"


#ifndef UNIX_PATH_MAX
#define UNIX_PATH_MAX 108
#endif

void set_fl(int fd, int flags) {

	int val;
	if ((val = fcntl(fd, F_GETFL, 0)) < 0) {
		printf("fcntl F_GETFL error\n");
		return ;
	}
	val |= flags;

	if (fcntl(fd, F_SETFL, val) < 0) {
		printf("fcntl F_SETFL error\n");
		return ;
	}
}

void clr_fl(int fd, int flags) {

	int val;
	if ((val = fcntl(fd, F_GETFL, 0)) < 0) {
		printf("fcntl F_GETFL error\n");
		return ;
	}
	val &= ~flags;

	if (fcntl(fd, F_SETFL, val) < 0) {
		printf("fcntl F_SETFL error\n");
		return ;
	}
}








