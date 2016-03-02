#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <linux/un.h>

main()
{
	int fd;
	int r;
	char buf[200];
	//1.����socket
	fd=socket(AF_UNIX,SOCK_DGRAM,0);
	if(fd==-1) printf("socket err:%m\n"),exit(-1);
	printf("socket�ɹ�!\n");
	//2.���챾���ļ���ַ
	struct sockaddr_un addr={0};
	addr.sun_family=AF_UNIX;
	memcpy(addr.sun_path,"my.sock",
					strlen("my.sock"));
	
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
