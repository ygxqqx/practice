#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/shm.h>
#include <sys/ipc.h>
key_t key;
int shmid;
int *p;
void deal(int s)
{
	if(s==2)
	{
		//4.卸载共享内存shmdt
		shmdt(p);
		exit(0);
	}
}
main()
{
	signal(SIGINT,deal);	
	//1.创建共享内存shmget
	key=ftok(".",255);
	if(key==-1) printf("ftok error:%m\n"),exit(-1);
	
	shmid=shmget(key,4,0);
	if(shmid==-1) printf("get error:%m\n"),exit(-1);
	//2.挂载共享内存shmat
	p=shmat(shmid,0,0);
	if(p==(int*)-1) printf("at error:%m\n"),exit(-1);
	//3.访问共享内存
	while(1)
	{		
		sleep(1);
		printf("%d\n",*p);
	}
	
	
}
