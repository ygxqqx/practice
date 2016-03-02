#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <stdio.h>
main()
{
	int *p=mmap(
		NULL,
		getpagesize(),
		PROT_READ,
		MAP_ANONYMOUS|MAP_SHARED,
		0,0);
	*p=20;
	*(p+1)=30;
	*(p+2)=40;
	
	printf("%d\n",p[2]);
	munmap(p,4096);
}
