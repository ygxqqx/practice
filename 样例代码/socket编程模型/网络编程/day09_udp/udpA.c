#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

main()
{
	int fd;//socket��������
	struct sockaddr_in ad;//������IP��ַ
	char buf[100];//�������ݻ���
	
	struct sockaddr_in ad_snd;//������IP��ַ
	socklen_t len;//������IP�ĳ���
	int r;
	
	fd=socket(AF_INET,SOCK_DGRAM,17);
	if(fd==-1) printf("socket:%m\n"),exit(-1);
	printf("����socket�ɹ�!\n");
	
	ad.sin_family=AF_INET;
	ad.sin_port=htons(11111);
	inet_aton("192.168.180.92",&ad.sin_addr);
	r=bind(fd,(struct sockaddr*)&ad,sizeof(ad));
	if(r==-1) printf("bind err:%m\n"),exit(-1);
	printf("�󶨳ɹ�!\n");
	
	while(1)
	{
		len=sizeof(ad_snd);
		r=recvfrom(fd,buf,sizeof(buf)-1,0,
				(struct sockaddr*)&ad_snd,&len);
		if(r>0){
			buf[r]=0;
			printf("������IP:%s,�˿�:%hu,����:%s\n",
				inet_ntoa(ad_snd.sin_addr),
				ntohs(ad_snd.sin_port),buf);
			sendto(fd,"�Ź�!",strlen("�Ź�!"),0,
			(struct sockaddr*)&ad_snd,sizeof(ad_snd));
		}
		if(r==0)
		{
			printf("�ر�!\n");			
			break;
		}
		if(r==-1)
		{
			printf("�������!\n");			
			break;
		}
	}
	
	close(fd);
	
}
