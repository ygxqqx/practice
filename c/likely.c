#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define unlikely(expr) (__builtin_expect(!!(expr), 0))

#define likely(expr) (__builtin_expect(!!(expr), 1))

int main() {
	char ptr[] = "nihao";
	char *p = NULL;
	int ret = -10;
	if (likely(p)) {			//likely p时 执行else ptr时执行 if
		printf("true====\n");
	} else {
		printf("false------\n");
	}
	printf("=================================\n");
	if (unlikely(ret > 0)) {			
		printf("true====\n");
	} else {
		printf("false------\n");
	}

	return 0;
}

