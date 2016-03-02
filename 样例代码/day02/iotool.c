#include <stdio.h>
int inputInt(const char *info)
{
	int r;
	printf("%s:",info);
	scanf("%d",&r);
	return r;
}
