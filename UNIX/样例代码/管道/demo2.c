#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
main()
{
	int fd[2];
	pipe(fd);
	if(fork())
	{//parent
		close(fd[0]);//只负责写
		while(1)
		{
			write(fd[1],"Hello",5);
			sleep(1);
		}
	}
	else
	{//child
		char buf[20];
		int r;
		close(fd[1]);//只负责读
		while(1)
		{
			r=read(fd[0],buf,20);
			buf[r]=0;
			printf("::%s\n",buf);
		}
	}
}
