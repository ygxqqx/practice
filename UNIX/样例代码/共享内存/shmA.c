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
int i=0;
void deal(int s)
{
	if(s==SIGINT)
	{
		//4.卸载共享内存shmdt
		shmdt(p);
		//5.删除共享内存shctl
		shmctl(shmid,IPC_RMID,0);
		exit(0);
	}
}
main()
{
	
	signal(SIGINT,deal);
	//1.创建共享内存shmget
	key=ftok(".",255);
	if(key==-1) printf("ftok error:%m\n"),exit(-1);
	
	shmid=shmget(key,4,IPC_CREAT|IPC_EXCL|0666);
	if(shmid==-1) printf("get error:%m\n"),exit(-1);
	//2.挂载共享内存shmat
	p=shmat(shmid,0,0);
	if(p==(int*)-1) printf("at error:%m\n"),exit(-1);
	//3.访问共享内存
	while(1)
	{
		*p=i;
		sleep(1);
		i++;
	}
	
}
