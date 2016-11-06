#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

int main(int argc, char *argv[]) {

	pid_t pid;
	int num = 10;
	printf("before fork:%d\n", getpid());
	pid = fork();
	if (pid == -1) {
		perror("fork error");
	}
	if (pid == 0) {
		num++;
		printf("parent num is:%d\n", num);
		printf("child :%d\n", getpid());
		//vfork + execve
		// execve("./hello", NULL, NULL);
	} else {
		num++;
		printf("parent num is:%d\n", num);
		printf("parent :%d\n", getpid());
	}
	return 0;
}



