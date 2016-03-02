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
	
	fd=socket(PF_INET,SOCK_DGRAM,0);
	if(fd==-1) printf("1:%m\n"),exit(-1);
	//1.选项
	r=setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,
				&opt,sizeof(opt));
	if(r==-1) printf("2:%m\n"),exit(-1);
	
	dr.sin_family=AF_INET;
	dr.sin_port=htons(9999);
	//2.广播地址
	dr.sin_addr.s_addr=inet_addr("192.168.180.255");
	
	r=bind(fd,(struct sockaddr*)&dr,sizeof(dr));
	if(r==-1) printf("3:%m\n"),exit(-1);
	
	r=recv(fd,buf,100,0);
	if(r>0)
	{
		buf[r]=0;
		printf("广播数据：%s\n",buf);
	}
	close(fd);
	
}
