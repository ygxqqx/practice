#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <signal.h>


#define ERR_EXIT(m) \
	do \
	{ \
		perror(m); \
		exit(EXIT_FAILURE); \
	} while(0)

typedef struct Teacher
{
	char name[64];
	int age ;
}Teacher;

//演示两个进程间通过 sigqueue 发送数据
//struct sigaction act;
//	act.sa_sigaction = myHandle_forsigaction; 接受数据

/*
void myHandle_forsigaction(int signum, siginfo_t *s_t, void *p) {
		Teacher *pt = NULL;
		printf("recv signum : %d \n", signum);
		pt = s_t->si_value.sival_ptr;
		if (pt == NULL) {
			printf("pt is null\n");	
		}
		else {
			printf("pt.name:%s pt.age:%d \n", pt->name, pt->age);	
		}
}
*/



//用新的回到函数接受数据。。。。  
void myHandle_forsigaction(int signum, siginfo_t *s_t, void *p) {
	//printf("recv a sig=%d data=%d data=%d\n", sig, info->si_value.sival_int, info->si_int);
	int myint = 0;
	printf("recv signum : %d \n", signum);
	myint = s_t->si_value.sival_int;
	printf("%d %d \n", myint, s_t->si_int );
}


int main(int argc, char *argv[]) {

	pid_t 	pid;
	int ret = 0;
	struct sigaction act;
	act.sa_sigaction = myHandle_forsigaction;
	sigemptyset(&act.sa_mask);
	//如果父进程的T回调函数， 准备接受额外数据
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGINT, &act, NULL) < 0) {
		ERR_EXIT("sigaction error");
	}
		
	pid = fork();
	if (pid == -1) {
		printf("fork err...\n");
		return 0;
	}
	
	if (pid == 0) {
		int i = 0;
		/*
		Teacher *t = (Teacher *)malloc(sizeof(Teacher));
		memset(t, 0, sizeof(Teacher));
		strcpy(t->name, "name");
		t->age = 33;
		*/
	   union sigval  mysigval;
	   //mysigval.sival_ptr = (void *)&t;
	   mysigval.sival_int = 222;	//外带的数据
		//kill(getppid(), SIGINT);
		//带额外数据
		for (i=0; i<10; i++) {
			ret  = sigqueue(getppid(), SIGINT, mysigval);
			if (ret != 0) {
				printf("sigqueue .....\n");
				exit(0);
			} else {
				printf("sigqueue...successs\n");
				sleep(2);
			}
		}

	} else if (pid > 0) {
		for (;;) {
			pause();
		}
	}

	return 0;
}

