#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
void handle(int s)
{
	printf("�ⲿ�û��жϴ���...!\n");
	sleep(3);
	printf("�ⲿ�û��жϴ������!\n");
}
main()
{
	int sum=0;
	int i;
	sigset_t sigs,sigt,sigu;
	sigemptyset(&sigs);
	sigemptyset(&sigt);
	sigemptyset(&sigu);
	
	sigaddset(&sigs,SIGINT);
	//sigfillset(&sigs);
	
	signal(SIGINT,handle);
	
	sigprocmask(SIG_BLOCK,&sigs,0);
	for(i=0;i<10;i++)
	{			
		printf("���ڿ�����Ӱ<%d>!\n",i);
		sleep(5);//ģ��ҵ����ʱ��Ƚϳ�
		printf("���ڿ�����Ӱ<%d>���!\n",i);
		sigpending(&sigu);
		if(sigismember(&sigu,SIGINT))
		{
			sigsuspend(&sigt);
		}		
	}
	printf("���е�Ӱ�������\n",sum);
	sigprocmask(SIG_UNBLOCK,&sigs,0);
	printf("over!\n");
}
