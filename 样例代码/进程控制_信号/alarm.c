#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
void deal(int s)
{
	printf("Æð´²!\n");
	
}
main()
{
	struct itimerval v={0};
	
	signal(SIGALRM,deal);
	
	//v.it_value.tv_sec=3;
	v.it_value.tv_sec=0;
	v.it_value.tv_usec=1;
	v.it_interval.tv_sec=1;
	//alarm(5);
	setitimer(ITIMER_REAL,&v,0);
	while(1)
	{
		//.....
	}
}
