#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>

/*
#include <signal.h>

typedef void (*sighandler_t)(int);

sighandler_t signal(int signum, sighandler_t handler);
*/


//信号异步通知事件 。。。。。（我的应用程序dm01）可以随时被信号机制中断。。。
//如果我我写了信号处理函数handler
//那么当信号发生时，会自动调用我写的函数。。。。
void main() {
	//注册一个信号
	//SIGINT  是ctrl+c 会产生2号信号。。。 中断应用程序
	//signal(SIGINT, handler);
	pid_t pid;
	//signal(SIGQUIT, handler);
	signal(SIGCHLD, SIG_IGN); //父进程忽略子进程的退出
	//signal(SIGKILL, SIG_IGN); //父进程忽略子进程的退出
	
	pid = fork();
	if (pid == -1) {
		perror("fork err");
		exit(0);
	}
	
	if (pid == 0) {
		printf("child.....\n");
		exit(0);
	}

	while (1) {
		pause();
	}
	
	printf("main...Begin\n");	
}

void handler(int num) {
	printf("recv num:%d \n", num);	
	if (num == SIGQUIT) {
		//exit(0);
	}
}

//那么当信号发生时，会自动调用我写的函数。。。。
void main22() {
	char tmpchar;
	//注册一个信号
	//SIGINT  是ctrl+c 会产生2号信号。。。 中断应用程序
	signal(SIGINT, handler);
	
	
	printf("如果你键入a字符，那么将恢复 SIGINT 的行为\n");
	while ( (tmpchar = getchar()) != 'a' ) {
		pause();
	}
	//
	
	//让这个信号恢复默认行为 SIG_DFL
	signal(SIGINT, SIG_DFL);
	while (1) {
		pause();
	}
	
	printf("main...end\n");	
}


//测试函数返回值
void main8() {
	char tmpchar;
	//注册一个信号
	//SIGINT  是ctrl+c 会产生2号信号。。。 中断应用程序
	__sighandler_t old = signal(SIGINT, handler);
	if (SIG_ERR == old) {
		perror("signal err"); //errno
		
	}
	
	
	printf("如果你键入a字符，那么将恢复 SIGINT 的行为\n");
	while ( (tmpchar = getchar()) != 'a' ) {
		pause();
	}
	//
	
	//让这个信号恢复默认行为 SIG_DFL
	signal(SIGINT, old);
	while (1) {
		pause();
	}
	
	printf("main...end\n");
}

//测试函数返回值
void main11() {
	char tmpchar;
	//注册一个信号
	//SIGINT  是ctrl+c 会产生2号信号。。。 中断应用程序
 	if (signal(SIGINT, handler) == SIG_ERR) {
 			perror("signal err"); //errno
 			exit(0);
 	} 
	while (1) {
		pause();
	}
	
	printf("main...end\n");	
}



