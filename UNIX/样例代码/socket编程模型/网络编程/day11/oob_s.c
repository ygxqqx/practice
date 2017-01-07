#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <fcntl.h>
int fd,cfd;
void handle(int s)
{

	char data[100];
	int r;
	if(s==SIGURG)
	{
		r=recv(cfd,data,100,MSG_OOB);		
	
		data[r]=0;
		printf("$$%s\n",data);
	}
}
main()
{
	
	int opt=1;
	char buf[100];
	int r;
	struct sockaddr_in dr;
	
	fd=socket(PF_INET,SOCK_STREAM,0);
	if(fd==-1) printf("1:%m\n"),exit(-1);
	printf("1\n");
	dr.sin_family=AF_INET;
	dr.sin_port=htons(10000);	
	dr.sin_addr.s_addr=inet_addr("192.168.180.92");
	
	r=bind(fd,(struct sockaddr*)&dr,sizeof(dr));
	if(r==-1) printf("2:%m\n"),exit(-1);
	printf("2\n");
	r=listen(fd,10);
	if(r==-1) printf("3:%m\n"),exit(-1);
	printf("3\n");
	signal(SIGURG,handle);
	cfd=accept(fd,0,0);
	fcntl(cfd,F_SETOWN,getpid());
	if(cfd==-1) printf("4:%m\n"),exit(-1);
	printf("4\n");
	while(1)
	{
		r=recv(cfd,buf,100,0);
		if(r>0)
		{
			buf[r]=0;
			printf("接收数据：%s\n",buf);
		}		
		else
		{
			break;
		}		
	}
	close(cfd);
	close(fd);
	
}
