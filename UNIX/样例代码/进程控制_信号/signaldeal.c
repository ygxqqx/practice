#include <unistd.h>
#include <stdio.h>
#include <signal.h>
void handle(int s)
{
	printf("�����źŷ�����\n");	
}

main()
{
	//signal(SIGWINCH,handle);
	signal(35,handle);
	while(1)
	{
		//printf("������ִ��:%d!\n",getpid());
		//sleep(1);
	}
}
