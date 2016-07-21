#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void main() {

	char buf1[100] = {0};
	char buf2[100] = {0};
	char *p1 = buf1;
	char *p2 = buf2;
	strcpy(buf1, "adasfdsf");
	


	while(*p1 != '\0') {
	
		*p2++ = *p1++;
	}

	printf(":%s \n", buf2);

	system("pause");
}
