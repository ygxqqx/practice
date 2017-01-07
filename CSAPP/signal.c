#include "./tiny/csapp.h"

void hander(int sig) {
	pid_t pid;
	while ((pid = waitpid(-1, NULL, 0)) > 0) {
		printf("Hander reaped child %d\n", (int)pid);
	}
	if (errno != ECHILD) {
		printf("errno!\n");
	}
	sleep(1);
	return ;
}

void main() {
	
	int i, n;
	char buf[1024];
	if (signal(SIGCHLD, hander) == SIG_ERR) {
		printf("signal err!\n");
	}
	
	for (i = 0; i < 3; ++i) {
		if (fork() == 0) {
			printf("Hello from child %d\n", (int)getpid());
			sleep(1);
			exit(0);
		}
	}
	
	if ((n = read(STDIN_FILENO, buf, sizeof(buf))) < 0) {
		if (errno != EINTR) {
			printf("read err!\n");
		}
	} else {
		printf("read succ!\n");
	}
	/*
	while (1) {
	}
	*/
	exit(0);
}











