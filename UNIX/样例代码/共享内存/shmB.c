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
		//4.ж�ع����ڴ�shmdt
		shmdt(p);
		exit(0);
	}
}
main()
{
	signal(SIGINT,deal);	
	//1.���������ڴ�shmget
	key=ftok(".",255);
	if(key==-1) printf("ftok error:%m\n"),exit(-1);
	
	shmid=shmget(key,4,0);
	if(shmid==-1) printf("get error:%m\n"),exit(-1);
	//2.���ع����ڴ�shmat
	p=shmat(shmid,0,0);
	if(p==(int*)-1) printf("at error:%m\n"),exit(-1);
	//3.���ʹ����ڴ�
	while(1)
	{		
		sleep(1);
		printf("%d\n",*p);
	}
	
	
}
