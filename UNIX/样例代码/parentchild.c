#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
void deal(int s) {
	int status;
	wait(&status);
	printf("������.....\n");
	sleep(5);	
	printf("�������:%d!\n",WEXITSTATUS(status));
			
}
main() {
	
	if (fork() == 0) {
		//parent
		printf("child!\n");
		sleep(20);
		printf("�˳�!\n");
		exit(88);
	} else {		
		//child
		signal(17,deal);
		//while(1)
		//{
		//	printf("parent!\n");		
		//	sleep(1);
		//}
		sleep(20000);
		printf("parent!\n");
	}
}
