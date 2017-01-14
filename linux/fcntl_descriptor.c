#include "unix.h"

// ./main 1
// 注：1 为文件描述符

int main(int argc, char const *argv[]) {
	
	int val;

	if (argc != 2) {
		printf("argc !== 2. usage: a.out <descriptor#>\n");
	}
	if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0) {
		printf("fcntl error for fd %d\n", atoi(argv[1]));
	}

	switch (val & O_ACCMODE) {

		case O_RDONLY:
			printf("read only\n");
			break;
		case O_WRONLY:
			printf("write only\n");
			break;
		case O_RDWR:
			printf("read write\n");
			break;
		default:
			printf("unknown access mode\n");
	}

	if (val & O_APPEND) {
		printf(", append\n");
	} else if (val & O_NONBLOCK) {
		printf(", nonblocking\n");
	} else if (val & O_SYNC) {
		printf(", synchronous writes\n");
	}

	return 0;
}






