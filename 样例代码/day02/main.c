#include <stdio.h>
#include <unistd.h>
main()
{
	int r=inputInt("�������ΰ뾶");
	diamond(r);
	printf("%d\n",getpid());
	while(1);
}

