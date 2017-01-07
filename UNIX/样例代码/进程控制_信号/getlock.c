#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

main()
{
	int fd;
	struct flock lk={0};
	int r;
	
	fd=open("a.txt",O_RDWR);
	if(fd==-1) printf("::%m\n"),exit(-1);
	
	r=fcntl(fd,F_GETLK,&lk);
	if(r==0) 
		printf("得到锁成功!\n");
	if(lk.l_type==F_WRLCK)
	{
		printf("写锁!\n");
	}
	printf("start:%d,len:%d\n",lk.l_start,lk.l_len);
	
	printf("PID:%d\n",lk.l_pid);
	
}
