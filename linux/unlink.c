#include "unix.h"


int main(int argc, char const *argv[]) {

	if (open("main", O_RDWR) < 0) {
		printf("open error\n");
	}
	if (unlink("main") < 0) {
		printf("unlink error\n");
	}
	printf("file unlinked\n");
	sleep(5);
	printf("done\n");
	return 0;
}
