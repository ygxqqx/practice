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
	int r;
	struct sockaddr_in dr;
	
	//1.选项设置
	fd=socket(PF_INET,SOCK_DGRAM,0);
	if(fd==-1) printf("1:%m\n"),exit(-1);
	
	r=setsockopt(fd,SOL_SOCKET,SO_BROADCAST,
				&opt,sizeof(opt));
	if(r==-1) printf("2:%m\n"),exit(-1);
	dr.sin_family=AF_INET;
	dr.sin_port=htons(9999);
	//2.使用广播IP地址
	dr.sin_addr.s_addr=inet_addr("192.168.180.255");
	
	r=sendto(fd,"Hello",5,0,
		(struct sockaddr*)&dr,sizeof(dr));
	if(fd==-1) printf("3:%m\n");
	
	close(fd);
}
