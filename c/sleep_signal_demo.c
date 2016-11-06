#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>

static void
sig_alrm(int signo) {
	/* nothing to do, just return to wake up the pause */
}

unsigned int
sleep1(unsigned int seconds) {

	if (signal(SIGALRM, sig_alrm) == SIG_ERR) {
		return(seconds);
	}
	alarm(seconds);		/* start the timer */
	pause();//使进程挂起直到一个进程被捕获/* next caught signal wakes us up */
	return(alarm(0));	/* turn off timer, return unslept time */
}

void handler(int num) {

	printf("recv num: %d\n", num);
}

int main() {

	signal(SIGINT, handler);
	int n = 10;
	// n = sleep(n);
	do {
		n = sleep1(n);
	} while (n>0);
	printf("end=======:%d\n", n);
	return 0;
}
