#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

	int loop_num;
	int proc_num;
	printf("Emter process num: ");
	scanf("%d", &proc_num);
	printf("Emter loop num: ");
	scanf("%d", &loop_num);
	int i = 0;
	pid_t pid;
	int j = 0;
	for (i=0; i<proc_num; ++i) {
		pid = fork();
		if (pid == -1) {
			return -1;
		}
		if (pid == 0) {
			
			for (j=0; j<loop_num; ++j) {
				printf("====%d===\n", j);
			}
			exit(0);
		} else {
			;// wait(0);
		}
	}
	
	int ret;
	while (1) {
		ret = wait(NULL);
		if (ret == -1) {
			if (errno == EINTR) {
				continue;
			}
			break;
		}
	}
	printf("---------end-----------\n");
	return 0;
}
