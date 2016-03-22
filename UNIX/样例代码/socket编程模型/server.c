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
	//1.建立socket
	sfd=socket(AF_UNIX,SOCK_STREAM,0);
	if(sfd==-1) printf("socket err:%m\n"),exit(-1);
	printf("建立socket成功!\n");
	
	//2.绑定地址
	bzero(&addr,sizeof(addr));
	addr.sun_family=AF_UNIX;
	memcpy(addr.sun_path,"cs.sock",
		strlen("cs.sock")+1);
	r=bind(sfd,(struct sockaddr*)&addr,sizeof(addr));
	if(r==-1) printf("bind err:%m\n"),exit(-1);
	printf("bind成功!\n");
	
	//3.监听
	r=listen(sfd,10);
	if(r==-1) printf("listen err:%m\n"),exit(-1);
	printf("listen成功!\n");
	
	//4.接收客户
	cfd=accept(sfd,0,0);
	if(cfd==-1) printf("accept err:%m\n"),exit(-1);
	printf("建立连接者的状态成功!\n");
	//5.接收这个客户的数据
	while(1)
	{
		r=read(cfd,buf,sizeof(buf));
		if(r==0)
		{
			printf("连接者退出");
			break;
		}
		if(r==-1)
		{
			printf("scoket故障!\n");
			break;
		}
		buf[r]=0;
		printf("::%s\n",buf);
		write(cfd,"Hi",2);
		
	}
	//6.关闭客户
	close(cfd);
	//7.关闭整个socket
	close(sfd);
	
}
