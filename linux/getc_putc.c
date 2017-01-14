#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
	
	int c;
	while ((c = getc(stdin)) != EOF) { // 一次读取一个字符

		if ((putc(c, stdout)) == EOF) { // 然后将此字符写到标准输出
			printf("output error\n");
		}
	}
	if (ferror(stdin)) {
		printf("input error\n");
	}
	return 0;
}

