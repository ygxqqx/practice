#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <linux/un.h>

main()
{
	int sfd;
	int cfd;
	struct sockaddr_un addr;
	int r;
	char buf[100];
	//1.����socket
	sfd=socket(AF_UNIX,SOCK_STREAM,0);
	if(sfd==-1) printf("socket err:%m\n"),exit(-1);
	printf("����socket�ɹ�!\n");
	
	//2.�󶨵�ַ
	bzero(&addr,sizeof(addr));
	addr.sun_family=AF_UNIX;
	memcpy(addr.sun_path,"cs.sock",
		strlen("cs.sock")+1);
	r=bind(sfd,(struct sockaddr*)&addr,sizeof(addr));
	if(r==-1) printf("bind err:%m\n"),exit(-1);
	printf("bind�ɹ�!\n");
	
	//3.����
	r=listen(sfd,10);
	if(r==-1) printf("listen err:%m\n"),exit(-1);
	printf("listen�ɹ�!\n");
	
	//4.���տͻ�
	cfd=accept(sfd,0,0);
	if(cfd==-1) printf("accept err:%m\n"),exit(-1);
	printf("���������ߵ�״̬�ɹ�!\n");
	//5.��������ͻ�������
	while(1)
	{
		r=read(cfd,buf,sizeof(buf));
		if(r==0)
		{
			printf("�������˳�");
			break;
		}
		if(r==-1)
		{
			printf("scoket����!\n");
			break;
		}
		buf[r]=0;
		printf("::%s\n",buf);
		write(cfd,"Hi",2);
		
	}
	//6.�رտͻ�
	close(cfd);
	//7.�ر�����socket
	close(sfd);
	
}
