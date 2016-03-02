#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
main()
{
	int serverfd;
	int cfd;
	int a;
	struct sockaddr_in sadr;
	struct sockaddr_in cadr;
	socklen_t len;
	int r;
	char buf[1024];
	//1.socket
	serverfd=socket(AF_INET,SOCK_STREAM,0);
	if(serverfd==-1) printf("1:%m\n"),exit(-1);
	printf("����������socket�ɹ�!\n");
	//2.bind
	sadr.sin_family=AF_INET;
	sadr.sin_port=htons(9999);
	inet_aton("192.168.180.92",&sadr.sin_addr);
	r=bind(serverfd,
			(struct sockaddr*)&sadr,sizeof(sadr));
	if(r==-1) printf("2:%m\n"),exit(-1);
	printf("��������ַ�󶨳ɹ�!\n");
	
	//3.listen
	r=listen(serverfd,10);
	if(r==-1) printf("3:%m\n"),exit(-1);
	printf("�����������ɹ�!\n");
	
	//4.accept
	len=sizeof(cadr);
	cfd=accept(serverfd,
			(struct sockaddr*)&cadr,&len);
	printf("��������:%d,IP:%s:%u\n",
			cfd,inet_ntoa(cadr.sin_addr),
			ntohs(cadr.sin_port));		
	
	//5.�������ͻ��������ŵ�����
	while(1)
	{
		r=recv(cfd,&a,4,MSG_WAITALL);		
		if(r>0)
		{
			//buf[r]=0;
			printf("::%d\n",a);
		}
		
		if(r==0)
		{
			printf("���ӶϿ�!\n");
			break;
		}
		if(r==-1)
		{
			printf("�������!\n");
			break;
		}
	}
	close(cfd);
	close(serverfd);
}

