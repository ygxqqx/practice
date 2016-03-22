#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
main()
{
	int fd;
	int opt=1;
	char buf[100];
	int r;
	struct sockaddr_in dr;
	fd_set fds;
	
	fd=socket(PF_INET,SOCK_STREAM,0);
	if(fd==-1) printf("1:%m\n"),exit(-1);
	printf("1\n");
	dr.sin_family=AF_INET;
	dr.sin_port=htons(10000);	
	dr.sin_addr.s_addr=inet_addr("192.168.180.92");
	
	r=connect(fd,(struct sockaddr*)&dr,sizeof(dr));
	if(r==-1) printf("2:%m\n"),exit(-1);	
	while(1)
	{
		FD_ZERO(&fds);
		FD_SET(fd,&fds);
		select(fd+1,0,&fds,0,0);
		send(fd,"Hello",5,MSG_OOB);		
	}
	close(fd);
	
}
