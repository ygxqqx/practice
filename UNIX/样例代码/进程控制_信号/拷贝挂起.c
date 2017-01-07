#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
void handle(int s)
{
	printf("外部用户中断处理...!\n");
	sleep(3);
	printf("外部用户中断处理完毕!\n");
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
		printf("正在拷贝电影<%d>!\n",i);
		sleep(5);//模拟业务处理时间比较长
		printf("正在拷贝电影<%d>完毕!\n",i);
		sigpending(&sigu);
		if(sigismember(&sigu,SIGINT))
		{
			sigsuspend(&sigt);
		}		
	}
	printf("所有电影拷贝完毕\n",sum);
	sigprocmask(SIG_UNBLOCK,&sigs,0);
	printf("over!\n");
}
