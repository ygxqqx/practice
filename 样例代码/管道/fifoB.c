#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>
#include <stdlib.h>
int fd;
void end(int s)
{
	//�رչܵ�
	close(fd);
	exit(-1);
}
main()
{
	int i;	
	//�򿪹ܵ�
	signal(SIGINT,end);
	fd=open("my.pipe",O_RDWR);
	//shutdown(fd,SHUT_WR);
	while(1)
	{
		read(fd,&i,4);
		printf("%d\n",i);
	}	
}
