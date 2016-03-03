#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
extern int errno;
int main()
{
	void *p=sbrk(1000000000*2);
	if(p==(void*)-1)
	{
		//perror("Hello:");
		//printf("Memory:%m\n");
		printf("::%s\n",strerror(errno));
	}
	
}
