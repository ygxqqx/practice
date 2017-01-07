#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
main()
{
	int fd;
	struct flock lk;
	int r;
	//打开一个文件
	fd=open("a.txt",O_RDWR);
	if(fd==-1) printf(":%m\n"),exit(-1);
	//描述锁
	lk.l_type=F_WRLCK;
	lk.l_whence=SEEK_SET;
	lk.l_start=5;
	lk.l_len=10;
	//加锁
	r=fcntl(fd,F_SETLK,&lk);
	if(r==0) printf("加锁成功！\n");
	else	printf("加锁失败！\n");
	while(1);	
}
