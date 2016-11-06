#include <stdio.h>

void align_len(int *len) {

	if (*len%4) {
		*len += 4 - *len%4;
	}
}

int main(int argc, char *argv[]) {

	int len = 5;
	align_len(&len);
	printf("%d\n", len);
	return 0;
}
