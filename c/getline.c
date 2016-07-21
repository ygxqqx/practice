#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

// If *lineptr is NULL, then getline() will allocate a buffer for storing the line, which should be freed by the
// user program.  (In this case, the value in *n is ignored.)

// Alternatively,  before  calling  getline(), *lineptr can contain a pointer to a malloc(3)-allocated buffer *n
// bytes in size.  If the buffer is not large enough to hold the line, getline()  resizes  it  with  realloc(3),
// updating *lineptr and *n as necessary.

int
main(void) {

	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	fp = fopen("/home/ygxqqx/demo.c", "r");
	if (fp == NULL) {
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, fp)) != -1) {
		// printf("Retrieved line of length %zu :\n", read);
		printf("%s", line);
	}

	free(line);
	exit(EXIT_SUCCESS);
}