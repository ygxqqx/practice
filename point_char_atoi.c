#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
	int pid = 123;
	char ch[8];
	*(int *)ch = pid;
	strcpy(ch+4, "456");
	int n = atoi(ch);
	int a = *((int *)ch);
	printf("%d\n", a);
	return 0;
}
