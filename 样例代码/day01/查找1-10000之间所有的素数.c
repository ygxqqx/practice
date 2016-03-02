#include <stdio.h>
#include <unistd.h>
int isPrimer(int a)
{	
	int i;
	for(i=2;i<a;i++)
	{
		if(a%i==0)
		{
			return 1;			
		}
	}
	return 0;
}

main()
{
	int i=2;
	int b;
	int *r;
	int *p;
	p=sbrk(0);
	r=p;
	for(;i<100;i++)
	{
		b=isPrimer(i);
		if(b==0)
		{
			brk(r+1);
			*r=i;
			r=sbrk(0);
		}
	}
	
	i=0;
	r=p;
	while(r!=sbrk(0))
	{
		printf("%d\n",*r);
		r++;
	}
	brk(p);//free
	
}
