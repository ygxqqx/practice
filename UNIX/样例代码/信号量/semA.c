#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
//2.1.����һ��������
union semun {
	int	val;
	struct semid_ds *buf;
	unsigned short  *array;
	struct seminfo  *__buf;
};

main()
{
	key_t key;
	int semid;	//�ź���ID
	union  semun v;//2.2.�����ʼ��ֵ
	int r;
	struct sembuf op[1];
	//1.�����ź���
	key=ftok(".",99);
	if(key==-1) printf("ftok err:%m\n"),exit(-1);
	
	//semid=semget(key,1/*�ź����������*/,
	//		IPC_CREAT|IPC_EXCL|0666);
			
	semid=semget(key,1,0);//�õ��ź���
	if(semid==-1) printf("get err:%m\n"),exit(-1);
	
	printf("id:%d\n",semid);
	//2.��ʼ���ź���
	v.val=2;
	r=semctl(semid,0,SETVAL,v);//2.3�����ź�����ֵ
	if(r==-1) printf("��ʼ��ʧ��!\n"),exit(-1);

	//3.���ź���������������
	//3.1.�������
	op[0].sem_num=0;//�ź����±�
	op[0].sem_op=-1;//�ź���������λ������
	op[0].sem_flg=0;
	while(1)
	{
		r=semop(semid,op,1);
		printf("���������\n");
	}
	
	//4.ɾ��(���Բ�ɾ��)
	
}
