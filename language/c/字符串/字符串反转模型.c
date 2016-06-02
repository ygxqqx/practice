
#include "stdlib.h"
#include "stdio.h"
#include "string.h"


void main() {
	char p[] = "abcde";
	char c ;
	char *p1 = p;
	char *p2 = p + strlen(p) -1;

	while (p1 < p2) {
		c = *p1;
		*p1 = *p2;
		*p2 = c;
		++p1;
		--p2;
	}

	printf("p:%s \n", p);
	system("pause");

}