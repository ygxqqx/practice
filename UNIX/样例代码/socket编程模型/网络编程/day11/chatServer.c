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
	int sfd;
	int count;
	int r;
	struct sockaddr_in dr;
	fd_set fds;
	int maxfd;
	int i,j;
	char buf[1024];
	int fdall[100];
	
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(sfd==-1) printf("1:%m\n"),exit(-1);
	printf("socket ok!\n");
	
	dr.sin_family=AF_INET;
	dr.sin_port=htons(8866);
	dr.sin_addr.s_addr = htonl(INADDR_ANY);//inet_aton("192.168.11.139",&dr.sin_addr);
	int opt = 1;
	setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR,(const void *)&opt, sizeof(int));
	r=bind(sfd,(struct sockaddr*)&dr,sizeof(dr));
	if(r==-1) printf("2:%m\n"),close(sfd),exit(-1);
	printf("bind ok!\n");

	r=listen(sfd,10);
	if(r==-1) printf("3:%m\n"),close(sfd),exit(-1);
	printf("listen ok!\n");

	count=0;
	maxfd=0;
	FD_ZERO(&fds);
	for(i=0;i<100;i++)
	{
		fdall[i]=-1;
	}
	while(1)
	{
		
		FD_ZERO(&fds);
		maxfd=0;
		
		FD_SET(sfd,&fds);
		maxfd=maxfd>=sfd?maxfd:sfd;
		
		for(i=0;i<count;i++)
		{
			if(fdall[i]!=-1)
			{
				FD_SET(fdall[i],&fds);
				maxfd=maxfd>=fdall[i]?maxfd:fdall[i];
			}
		}
		
		r=select(maxfd+1,&fds,0,0,0);
		if(r==-1) 
		{
			printf("select err!\n");
			break;
		}		
		
		if(FD_ISSET(sfd,&fds))
		{
			fdall[count]=accept(sfd,0,0);
			if(fdall[count]==-1)
			{
				printf("accept error!\n");
				
				break;
			}
			printf("have client connect!\n");
			count++;
		}
		
		for(i=0;i<count;i++)
		{
			
			if( fdall[i]!=-1 &&
				FD_ISSET(fdall[i],&fds))
			{
				
				r=recv(fdall[i],buf,1023,0);
				if(r==0){
					printf("have client exit!\n");
					close(fdall[i]);
					fdall[i]=-1;
				}
				if(r==-1){
					printf("recv err!\n");
					close(fdall[i]);
					fdall[i]=-1;
				}
				if(r>0)
				{
					
					buf[r]=0;
					printf("recv data:%s\n",buf);
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
