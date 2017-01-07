#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <sys/poll.h>
main()
{	
	struct pollfd fds[1];
	int r;
	char buf[100];
	
	fds[0].fd=0;
	fds[0].events=POLLIN;
	while(1)
	{
		
		r=poll(fds,1,-1);
		if(fds[0].revents & POLLIN)
		{
			printf("有数据输入!\n");
			r=read(0,buf,99);
		}
	}
}
