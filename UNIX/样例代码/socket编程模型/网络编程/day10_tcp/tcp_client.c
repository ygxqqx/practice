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
	int i=0;
	//1.socket
	fd=socket(AF_INET,SOCK_STREAM,0);
	if(fd==-1) printf("1:%m\n"),exit(-1);
	printf("����socket�ɹ�!\n");
	//2.connect
	addr.sin_family=AF_INET;
	addr.sin_port=htons(9999);
	inet_aton("192.168.180.92",&addr.sin_addr);
	r=connect(fd,
			(struct sockaddr*)&addr,sizeof(addr));
	if(r==-1) printf("2:%m\n"),exit(-1);
	printf("���ӷ������ɹ�!\n");
	
	
	for(i=0;i<20;i++)
	{
		send(fd,&i,4,0);
	}
}
