#include <stdio.h>
#include <signal.h>
void h(int s)
{
	printf("��մ���int�ź�\n");
}
main()
{
	int sum=0;
	int i;
	//1.
	signal(SIGINT,h);
	sigset_t sigs,sigp,sigq;
	//2.
	sigemptyset(&sigs);
	sigemptyset(&sigp);
	sigemptyset(&sigq);
	
	sigaddset(&sigs,SIGINT);
	//3.
	sigprocmask(SIG_BLOCK,&sigs,0);
	for(i=1;i<=10;i++)
	{
		sum+=i;
		sigpending(&sigp);
		if(sigismember(&sigp,SIGINT))
		{
			printf("SIGINT���Ŷ�!\n");
			sigsuspend(&sigq);
			//ʹԭ�������ź���Ч������ԭ���ź�
			//ʹ�µ��ź�����,
			//��ĳ���źŴ������������
			//sigsuspend�ָ�ԭ�������źţ����� 
		}
		sleep(1);
	}
	printf("sum=%d\n",sum);
	sigprocmask(SIG_UNBLOCK,&sigs,0);
	printf("Over!\n");
}
