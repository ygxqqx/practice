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


void handler(int sig) {

	if (sig == SIGINT) {
		printf("recv a sig=%d\n", sig);
		printf("\n\n\n");
		//fflush(stdout);
	} else if (sig == SIGQUIT) {
		sigset_t uset;
		sigemptyset(&uset);
		sigaddset(&uset, SIGINT);
		//ctr + \ 
		//解除屏蔽SIGINT信号
		sigprocmask(SIG_UNBLOCK, &uset, NULL);
		//signal(SIGINT, SIG_DFL) ;
	}
}

void printsigset(sigset_t *set) {
	int i;
	for (i=1; i<NSIG; ++i) {
		if (sigismember(set, i)) {
			putchar('1');
		} else {
			putchar('0');
		}
	}
	printf("\n");
}


int main02(int argc, char *argv[]) {
	sigset_t pset;
	
	//sigset_t bset;
	//sigemptyset(&bset);
	//sigaddset(&bset, SIGINT);
	
	if (signal(SIGINT, handler) == SIG_ERR)
		ERR_EXIT("signal error");
	/*
	if (signal(SIGQUIT, handler) == SIG_ERR)
		ERR_EXIT("signal error");
		sigprocmask(SIG_BLOCK, &bset, NULL);
	*/
	
	for (;;) {
		//获取信号未决状态字
		sigpending(&pset); 
		printsigset(&pset);
		sleep(2);
	}
	return 0;
}


int main(int argc, char *argv[]) {
	sigset_t pset; 
	sigset_t bset; 
	
	sigemptyset(&bset);
	sigaddset(&bset, SIGINT);
	
	if (signal(SIGINT, handler) == SIG_ERR)
		ERR_EXIT("signal error");
		
	if (signal(SIGQUIT, handler ) == SIG_ERR)
		ERR_EXIT("signal error");

	//sigprocmask 读取或更改进程的信号屏蔽状态字
	sigprocmask(SIG_BLOCK, &bset, NULL);

	for (;;) {
		//获取信号未决状态字
		sigpending(&pset);
		printsigset(&pset);
		sleep(1);
	}
	return 0;
}



