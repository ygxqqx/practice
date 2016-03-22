#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
//2.1.定义一个联合体
union semun {
	int	val;
	struct semid_ds *buf;
	unsigned short  *array;
	struct seminfo  *__buf;
};

main()
{
	key_t key;
	int semid;	//信号量ID
	union  semun v;//2.2.定义初始化值
	int r;
	struct sembuf op[1];
	//1.创建信号量
	key=ftok(".",99);
	if(key==-1) printf("ftok err:%m\n"),exit(-1);
	
	//semid=semget(key,1/*信号量数组个数*/,
	//		IPC_CREAT|IPC_EXCL|0666);
			
	semid=semget(key,1,0);//得到信号量
	if(semid==-1) printf("get err:%m\n"),exit(-1);
	
	printf("id:%d\n",semid);
	//2.初始化信号量
	v.val=2;
	r=semctl(semid,0,SETVAL,v);//2.3设置信号量的值
	if(r==-1) printf("初始化失败!\n"),exit(-1);

	//3.对信号量进行阻塞操作
	//3.1.定义操作
	op[0].sem_num=0;//信号量下标
	op[0].sem_op=-1;//信号量操作单位与类型
	op[0].sem_flg=0;
	while(1)
	{
		r=semop(semid,op,1);
		printf("解除阻塞！\n");
	}
	
	//4.删除(可以不删除)
	
}
