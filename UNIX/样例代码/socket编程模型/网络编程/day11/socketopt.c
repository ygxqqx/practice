#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

main()
{
	int fd;
	int type;
	int len;
	len=sizeof(type);
	
	fd=socket(AF_INET,SOCK_DGRAM,0);
	getsockopt(fd,SOL_SOCKET,SO_RCVBUF,&type,&len);
	printf("缓冲大小:%u\n",type);
	/*
	getsockopt(fd,SOL_SOCKET,SO_TYPE,&type,&len);
	
	printf("%u:%u\n",SOCK_STREAM,type);
	if(type & SOCK_STREAM)
	{
		printf("流!\n");
	}
	if(type & SOCK_DGRAM)
	{
		printf("报文!\n");
	}
	*/
}
