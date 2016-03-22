#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
main()
{
	int fd;
	struct sockaddr_in addr;
	int r;
	char buf[1024];

	//1.socket
	fd=socket(AF_INET,SOCK_DGRAM,0);
	if(fd==-1) printf("1:%m\n"),exit(-1);
	printf("建立socket成功!\n");
	//2.bind
	addr.sin_family=AF_INET;
	addr.sin_port=htons(11111);
	inet_aton("192.168.180.92",&addr.sin_addr);
	r=bind(fd,
			(struct sockaddr*)&addr,sizeof(addr));
	if(r==-1) printf("2:%m\n"),exit(-1);
	printf("绑定成功!\n");
	
	
	while(1)
	{
		r=recv(fd,buf,1024,0);
		buf[r]=0;
		printf("::%s\n",buf);
	}
	close(fd);
}
