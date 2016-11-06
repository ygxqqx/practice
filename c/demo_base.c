#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {

	pid_t pid;
	printf("before fork:%d\n", getpid());
	int fd;
	fd = open("file", O_WRONLY);
	pid = fork();
	if (pid == -1) {
		perror("fork error");
	}
	if (pid == 0) {
		printf("child :%d\n", getpid());
		write(fd, "child", 5);
		close(fd);
	} else {
		write(fd, "father", 6);
		printf("parent :%d\n", getpid());
		close(fd);
	}
	return 0;
}


