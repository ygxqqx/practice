#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
main()
{
	int fd;
	struct flock lk;
	int r;
	//��һ���ļ�
	fd=open("a.txt",O_RDWR);
	if(fd==-1) printf(":%m\n"),exit(-1);
	//������
	lk.l_type=F_WRLCK;
	lk.l_whence=SEEK_SET;
	lk.l_start=5;
	lk.l_len=10;
	//����
	r=fcntl(fd,F_SETLK,&lk);
	if(r==0) printf("�����ɹ���\n");
	else	printf("����ʧ�ܣ�\n");
	while(1);	
}
