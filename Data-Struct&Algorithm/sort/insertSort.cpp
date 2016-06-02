#include <stdio.h>
#include <stdlib.h>

void swap(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}

void insertSort(int num[], int n) {

	if (num == NULL || n<= 0) {
		return;
	} else {
		for (int i=0; i<n; ++i) {
			for (int j=i+1; j>0&&num[j]<num[j-1]; --j) {
				swap(num[j], num[j-1]);
			}
		}
	}

	return;
}


void print(int num[], int n) {
	for (int i=0; i<n; ++i) {
		printf("%d ", num[i]);
	}
	printf("\n");
}

int main() {

	int num[] = {12, 1, 34, 33, 56, 7};
	insertSort(num, 6);
	print(num, 6);
	return 0;
}
