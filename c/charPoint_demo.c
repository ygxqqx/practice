#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>

char *get_point() {

	
}

int main(int argc, char const *argv[]) {
	/* code */
	char *p = get_point();
	printf("%s\n", p);
	return 0;
}

