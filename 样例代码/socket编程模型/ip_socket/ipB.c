#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
//1
#include <netinet/in.h>
#include <arpa/inet.h>
main()
{
	int fd;
	int r;
	//2
	struct sockaddr_in addr={0};
	//1.����socket
	//3
	fd=socket(AF_INET,SOCK_DGRAM,0);
	//2.���ӵ�ָ���ĵ�ַ
	//4
	addr.sin_family=AF_INET;
	addr.sin_port=htons(9999);
	addr.sin_addr.s_addr
		=inet_addr("192.168.180.92");
	
	r=connect(fd,(struct sockaddr*)&addr,
			sizeof(addr));
	//3.��������
	write(fd,"Hello!Maomaochong!",
		strlen("Hello!Maomaochong!"));
	//4.�ر�
	close(fd);dd
}
