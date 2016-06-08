#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <signal.h>


int main()
{
	pid_t pid;
	int ret = 0;
	
	printf("befor fork pid:%d \n", getpid());
	int abc = 10;
	pid = vfork(); //errno
	if (pid == -1) {
		//printf("pid < 0 err.\n");
		perror("tile");
		return -1;
	}
	if (pid > 0) {
		
		printf("parent: pid:%d \n", getpid());
		
	
	} else if (pid == 0) {
		printf("child: %d, parent: %d \n", getpid(), getppid());
		//printf("abc:%d\n", abc);
		
		//把自己写应用程序启动起来
		//
	   	ret =  execve("./main", NULL, NULL);
	   	if (ret == -1) {
			perror("execve:");
		}
	   	printf("execve 测试有没有执行\n");
		exit(0);
	}

	printf("fork after....\n");
	return 0;
}


int main01()
{
	pid_t pid;
	int ret = 0;
	
	printf("befor fork pid:%d \n", getpid());
	int abc = 10;
	pid = vfork(); //errno
	if (pid == -1) {
		//printf("pid < 0 err.\n");
		perror("tile");
		return -1;
	}
	if (pid > 0) {
		printf("parent: pid:%d \n", getpid());
	} else if (pid == 0) {
		printf("child: %d, parent: %d \n", getpid(), getppid());
		//printf("abc:%d\n", abc);
		
		//把自己写应用程序启动起来
		//通过一个应用程序执行命令
		char *const argv[] = {"ls", "-l", NULL};
	   	ret =  execve("/bin/ls", argv, NULL);
	   	if (ret == -1) {
			perror("execve:");
		}
	    	printf("execve 测试有没有执行\n");	
		exit(0);
	}

	//printf("fork after....\n");
	return 0;
}



