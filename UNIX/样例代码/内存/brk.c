#include <stdio.h>
#include <unistd.h>

main()
{
	/*
	int *p1=sbrk(4);//返回空闲地址，并修改指针为＋size
	int *p2=sbrk(200);
	int *p3=sbrk(-4);
	int *p4=sbrk(-4);
	int *p5=sbrk(-4);	
	printf("%p\n",p1);
	printf("%p\n",p2);
	printf("%p\n",p3);
	printf("%p\n",p4);
	printf("%p\n",p5);
	printf("%d\n",getpid());
	*/
	int *p=sbrk(0);
	brk(p+1);
	*p=800;
	brk(p);
	*p=99;
	
	
	//while(1);
}
