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
	struct sockaddr_in dr;
	char strreq[1024];
	char buf[10*1024];
	int r; 
	//����socket
	fd=socket(AF_INET,SOCK_STREAM,0);
	
	//���ӷ�����192.168.0.72
	dr.sin_family=AF_INET;
	dr.sin_port=htons(80);
	dr.sin_addr.s_addr=inet_addr("192.168.0.72");
	r=connect(fd,(struct sockaddr*)&dr,sizeof(dr));
	
	//����http�����ַ���
	sprintf(strreq,
		"GET /index.php HTTP/1.1\r\n"
		"Host: 192.168.0.72:80\r\n"
		"User-Agent: Mozilla/5.0\r\n"
		"Accept: text/html,image/png\r\n"
		"Accept-Language: zh-cn\r\n"
		"Accept-Charset: gb2312,utf-8\r\n"
		"Keep-Alive: 300\r\n"
		"Connection: keep-alive\r\n"
		"\r\n");
	//����http�����ַ���
	r=send(fd,strreq,strlen(strreq),0);
	//�ȴ���������Ӧ
	//while(1)
	//{
		r=recv(fd,buf,1024,0);
		//if(r<=0) break;
		printf("========================\n");
		printf("%s\n",buf);
		printf("========================\n");
	//}
	close(fd);
}
