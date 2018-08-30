#include <stdio.h>

int main() {
	
	int *n;
	int size = sizeof(n);
	int data[] = {1, 2, 3};
	printf("point: %d\n", size);
	printf("Array: %lu\n", sizeof(data) / sizeof(int));
	return 0;
}
