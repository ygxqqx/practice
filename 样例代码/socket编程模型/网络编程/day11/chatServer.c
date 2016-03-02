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
	int sfd;//��������������
	int fdall[100];//�ͻ���������
	int count;//�ͻ�����
	int r;//����ֵ���쳣����
	struct sockaddr_in dr;//IP��ַ��˿�
	fd_set fds;//��select��ص��������ż���
	int maxfd;//����ļ���������
	int i,j;//ѭ������
	char buf[1024];//�ͻ���������
	
	//1.����socket
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(sfd==-1) printf("1:%m\n"),exit(-1);
	printf("socket ok!\n");
	//2.�󶨵�ַ��˿�
	dr.sin_family=AF_INET;
	dr.sin_port=htons(8866);
	inet_aton("192.168.180.92",&dr.sin_addr);
	r=bind(sfd,(struct sockaddr*)&dr,sizeof(dr));
	if(r==-1) printf("2:%m\n"),close(sfd),exit(-1);
	printf("bind ok!\n");
	//3.����
	r=listen(sfd,10);
	if(r==-1) printf("3:%m\n"),close(sfd),exit(-1);
	printf("listen ok!\n");
	//��ʼ��
	count=0;
	maxfd=0;
	FD_ZERO(&fds);
	for(i=0;i<100;i++)
	{
		fdall[i]=-1;
	}
	while(1)
	{
		//4.����������������ż���
		//4.1.���
		FD_ZERO(&fds);
		maxfd=0;
		//4.2.�����������������
		FD_SET(sfd,&fds);
		maxfd=maxfd>=sfd?maxfd:sfd;
		//4.3.����ͻ���������
		for(i=0;i<count;i++)
		{
			if(fdall[i]!=-1)
			{
				FD_SET(fdall[i],&fds);
				maxfd=maxfd>=fdall[i]?maxfd:fdall[i];
			}
		}
		//5.ʹ��selectѭ�������������ż���
		r=select(maxfd+1,&fds,0,0,0);
		if(r==-1) 
		{
			printf("����������!\n");
			break;
		}		
		//6.�������������:		
		//6.1.�пͻ�����:��������������
		if(FD_ISSET(sfd,&fds))
		{
			fdall[count]=accept(sfd,0,0);
			if(fdall[count]==-1)
			{
				printf("����������!\n");
				//�ͷ����пͻ�
				break;
			}
			printf("�пͻ�����!\n");
			count++;
		}
		//6.2.�пͻ���������:�ͻ���������
		for(i=0;i<count;i++)
		{
			//�ж��ı����������Ƿ����
			if( fdall[i]!=-1 &&
				FD_ISSET(fdall[i],&fds))
			{
				//��ȡ����
				r=recv(fdall[i],buf,1023,0);
				if(r==0){
					printf("�пͻ��˳�!\n");
					close(fdall[i]);
					fdall[i]=-1;
				}
				if(r==-1){
					printf("�������!\n");
					close(fdall[i]);
					fdall[i]=-1;
				}
				if(r>0)
				{
					//�㲥����
					buf[r]=0;
					printf("�㲥����:%s\n",buf);
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
