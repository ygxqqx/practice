#include <stdio.h>
main()
{
	int a=inputInt();
	int r=isPrimer(a);
	if(r==1)
	{
		printf("%d������!\n",a);
	}
	else
	{
		printf("%d�Ǻ���!\n",a);
	}
}
