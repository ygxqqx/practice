#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//1.
#include <netinet/in.h>
#include <arpa/inet.h>

main()
{
	int fd;
	int r;
	char buf[200];
	//1.����socket
	//2
	fd=socket(AF_INET,SOCK_DGRAM,0);
	if(fd==-1) printf("socket err:%m\n"),exit(-1);
	printf("socket�ɹ�!\n");
	//2.���챾���ļ���ַ
	//3.
	struct sockaddr_in addr={0};
	addr.sin_family=AF_INET;
	addr.sin_port=htons(9999);
	addr.sin_addr.s_addr=
			inet_addr("192.168.180.92");
	//3.��socket���ڵ�ַ��
	r=bind(fd,(struct sockaddr*)&addr,sizeof(addr));
	if(r==-1) printf("bind err:%m\n"),exit(-1);
	printf("��ַ�󶨳ɹ�!\n");
	
	//4.��������
	while(1)
	{
		bzero(buf,sizeof(buf));
		r=read(fd,buf,sizeof(buf));
		buf[r]=0;
		printf("%s\n",buf);
	}	
	
	//5.�ر�
	close(fd);
	//6.ɾ��socket�ļ�
	unlink("my.sock");
	
}
