#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
// 创建守护进程步骤
// 调用fork(),创建新进程，它会是将来的守护进程
// 在父进程中调用exit，保证子进程不是进程组组长
// 调用setsid创建新的会话期
// 将当前目录改为根目录 （如果把当前目录作为守护进程的目录，当前目录不能被卸载，它作为守护进程的工作目录了。）
// 将标准输入、标准输出、标准错误重定向到/dev/null

//int daemon(int nochdir, int noclose);//系统调用
int my_daemon(int nochdir, int noclose) {
	
	int i = 0;
	pid_t pid;
	pid = fork();
	if (pid == -1) {
		perror("fork err");
		exit(0);
	}
	if (pid > 0) {
		exit(0);
	}
	printf("pid:%d \n", getpid());
	pid = setsid();
	if (pid == -1) {
		perror("fork err");
		exit(0);
	}
	
	if (nochdir != 0)
		chdir("/");
	
	if (noclose != 0) {
		for (i=0; i<3; i++) {
			close(i);
		}
	}

	open("/dev/null", O_RDWR); 
	dup(0);
	dup(1);
	
	while (1) {
		sleep(1);
	}
	
	printf("hello\n");
	return 0;
}


int main()
{
	my_daemon(1, 1);
	return 0;
}




