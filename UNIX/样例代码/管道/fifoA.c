#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>
#include <stdlib.h>
int fd;
int i;
void  end(int s)
{
	//�رչܵ�
	close(fd);		
	//ɾ���ܵ�
	unlink("my.pipe");
	exit(-1);
} 

main()
{
	signal(SIGINT,end);	
	//�����ܵ�
	mkfifo("my.pipe",0666);
	//�򿪹ܵ�
	fd=open("my.pipe",O_RDWR);
	//shutdown(fd,SHUT_RD);
	i=0;
	while(1)
	{
		//ÿ��1��д����
		sleep(1);
		write(fd,&i,4);
		i++;
	}
	
}
