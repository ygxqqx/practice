#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
void handle(int s)
{
	char buf[200];
	int r;
	r=read(0,buf,199);
	buf[r]=0;
	printf("::%s",buf);
}
main()
{
	
	fcntl(0,F_SETFL,O_ASYNC);
	fcntl(0,F_SETOWN,getpid());
	signal(SIGIO,handle);
	while(1);	
}
