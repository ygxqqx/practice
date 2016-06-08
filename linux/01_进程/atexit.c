#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <signal.h>

////exit(0)是c库函数 =  _exit(0); //系统调用
//\n能启动刷新缓冲区的作用
//

void bye1(void) {
	printf("bye1...do\n");
}

void bye2(void) {
	printf("bye2...do\n");
}


int main01() {
	
	atexit(bye1);
	atexit(bye2);
	printf("hello....  fddddddddd1111");
	fflush(stdout);
	//exit(0)是c库函数 =======其他操作。。。。在调用_exit
	_exit(0); //系统调用
}

int main() {
	
	atexit(bye1);
	atexit(bye2);
	printf("hello....  fddddddddd1111\n");
	//abort();
	sleep(5);
	//exit(0); //是c库函数 =======其他操作。。。。在调用_exit
	return 0;
}






