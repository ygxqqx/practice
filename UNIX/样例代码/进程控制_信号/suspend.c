#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
void handle(int s)
{
	printf("–≈∫≈∏…»≈!\n");
}
main()
{
	sigset_t sigs;
	sigemptyset(&sigs);
	sigaddset(&sigs,2);
	sigaddset(&sigs,10);
	signal(SIGUSR2,handle);
	sigsuspend(&sigs);
	//pause();	
	printf("over!\n");
}
