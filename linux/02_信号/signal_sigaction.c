
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


//演示信号从产生到抵达的整个过程
//信号的阻塞和解除阻塞综合实验
//设置信号阻塞和非阻塞，设置ctl+q来解除信号阻塞

#define ERR_EXIT(m) \
	do \
	{ \
		perror(m); \
		exit(EXIT_FAILURE); \
	} while(0)


void handler(int sig) {
	if (sig == SIGINT) {
		printf("recv a sig=%d\n", sig);
		//fflush(stdout);
	} else if (sig == SIGQUIT) {
		sigset_t uset;
		sigemptyset(&uset);
		sigaddset(&uset, SIGINT);
		//ctr + \ 用来接触  SIGINT 信号
		//解除阻塞
		sigprocmask(SIG_UNBLOCK, &uset, NULL);
		//signal(SIGINT, SIG_DFL) ;
	}
}


/*
       int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);

DESCRIPTION
       The sigaction() system call is used to change the action taken by a process on receipt of a specific signal.

       signum specifies the signal and can be any valid signal except SIGKILL and SIGSTOP.

       If act is non-null, the new action for signal signum is installed from act.  If oldact is non-null, the previous
       action is saved in oldact.

       The sigaction structure is defined as something like

              struct sigaction {
                  void (*sa_handler)(int);
                  void (*sa_sigaction)(int, siginfo_t *, void *);
                  sigset_t sa_mask;
                  int sa_flags;
                  void (*sa_restorer)(void);
              }

*/


 void handler2(int num, siginfo_t *info, void * p) {
 	printf("recv sig :%d\n", num);
 }
 
int main(int argc, char *argv[]) {
	struct sigaction act;
	act.sa_handler = handler;
	// act.sa_sigaction = handler2;
  	sigaction(SIGINT, &act, NULL);
	/*
	if (signal(SIGINT, handler) == SIG_ERR)
		ERR_EXIT("signal error");
		
	if (signal(SIGQUIT, handler ) == SIG_ERR)
		ERR_EXIT("signal error");
	*/
	for (;;) {
		sleep(1);
	}
	return 0;
}



