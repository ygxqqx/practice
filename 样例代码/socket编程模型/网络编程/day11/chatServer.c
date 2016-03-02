#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
main()
{
	int sfd;//服务器描述符号
	int fdall[100];//客户描述符号
	int count;//客户个数
	int r;//返回值（异常处理）
	struct sockaddr_in dr;//IP地址与端口
	fd_set fds;//被select监控的描述符号集合
	int maxfd;//最大文件描述符号
	int i,j;//循环变量
	char buf[1024];//客户聊天数据
	
	//1.建立socket
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(sfd==-1) printf("1:%m\n"),exit(-1);
	printf("socket ok!\n");
	//2.绑定地址与端口
	dr.sin_family=AF_INET;
	dr.sin_port=htons(8866);
	inet_aton("192.168.180.92",&dr.sin_addr);
	r=bind(sfd,(struct sockaddr*)&dr,sizeof(dr));
	if(r==-1) printf("2:%m\n"),close(sfd),exit(-1);
	printf("bind ok!\n");
	//3.监听
	r=listen(sfd,10);
	if(r==-1) printf("3:%m\n"),close(sfd),exit(-1);
	printf("listen ok!\n");
	//初始化
	count=0;
	maxfd=0;
	FD_ZERO(&fds);
	for(i=0;i<100;i++)
	{
		fdall[i]=-1;
	}
	while(1)
	{
		//4.构造监听的描述符号集合
		//4.1.清空
		FD_ZERO(&fds);
		maxfd=0;
		//4.2.加入服务器描述符号
		FD_SET(sfd,&fds);
		maxfd=maxfd>=sfd?maxfd:sfd;
		//4.3.加入客户描述符号
		for(i=0;i<count;i++)
		{
			if(fdall[i]!=-1)
			{
				FD_SET(fdall[i],&fds);
				maxfd=maxfd>=fdall[i]?maxfd:fdall[i];
			}
		}
		//5.使用select循环控制描述符号集合
		r=select(maxfd+1,&fds,0,0,0);
		if(r==-1) 
		{
			printf("服务器崩溃!\n");
			break;
		}		
		//6.分两种情况处理:		
		//6.1.有客户连接:服务器描述符号
		if(FD_ISSET(sfd,&fds))
		{
			fdall[count]=accept(sfd,0,0);
			if(fdall[count]==-1)
			{
				printf("服务器崩溃!\n");
				//释放所有客户
				break;
			}
			printf("有客户连接!\n");
			count++;
		}
		//6.2.有客户发送数据:客户描述符号
		for(i=0;i<count;i++)
		{
			//判定改变描述符号是否存在
			if( fdall[i]!=-1 &&
				FD_ISSET(fdall[i],&fds))
			{
				//读取数据
				r=recv(fdall[i],buf,1023,0);
				if(r==0){
					printf("有客户退出!\n");
					close(fdall[i]);
					fdall[i]=-1;
				}
				if(r==-1){
					printf("网络故障!\n");
					close(fdall[i]);
					fdall[i]=-1;
				}
				if(r>0)
				{
					//广播数据
					buf[r]=0;
					printf("广播数据:%s\n",buf);
					for(j=0;j<count;j++)
					{
						if(fdall[j]!=-1)
						{
							send(fdall[j],buf,r,0);
						}
					}
				}
			}
		}
	}
}
