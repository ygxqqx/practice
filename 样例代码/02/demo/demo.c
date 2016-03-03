#include <stdio.h>
main()
{
	int a=inputInt();
	int r=isPrimer(a);
	if(r==1)
	{
		printf("%d是素数!\n",a);
	}
	else
	{
		printf("%d是合数!\n",a);
	}
}
