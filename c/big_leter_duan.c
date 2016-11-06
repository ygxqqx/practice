#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <arpa/inet.h>
#include <sys/wait.h>

// uint32_t htonl(uint32_t hostlong);

int main(int argc, char const *argv[]) {
	unsigned int num = 0x12345678;
	char *p = &num;
	if (p[0] == 0x78) {
		printf("letter duan: %d\n", p[0]);
	} else {
		printf("big duan\n");
	}

	//网络字节序
	uint32_t n = htonl(num);
	p = &n;
	if (p[0] == 0x78) {
		printf("letter duan: %d\n", p[0]);
	} else {
		printf("big duan: %d\n", p[0]);
	}
	return 0;
}
