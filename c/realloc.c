#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

	char *new_ptr;
	char *ptr = (char *)malloc(7);
	strcpy(ptr, "malloc");
	printf("%s\n", ptr);
	new_ptr = realloc(ptr, 20);
	ptr = new_ptr;
	char *p = ptr + 6;
	strcpy(p, "realloc");
	//sprintf(p, "%s", "realloc");
	printf("%s\n", ptr);
	return 0;
}


