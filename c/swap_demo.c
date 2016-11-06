#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <errno.h>
//面试题
void swap1(int *a, int *b) {

	int *p = NULL;
	*p = *a;	//错应为*p是取地址然后修改，而p指向空
	*a = *b;
	*b = *p;
}

void swap(int *a, int *b) {

	int p;
	p = *a;
	*a = *b;
	*b = p;
}

int main(int argc, char const *argv[]) {

	int a = 1, b = 2;
	swap(&a, &b);
	printf("a: %d, b: %d\n", a, b);
	/* code */
	return 0;
}


