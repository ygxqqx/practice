#include <stdio.h>
#include <stdlib.h>

void swap(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}
void print(int num[], int n) {
	for (int i=0; i<n; ++i) {
		printf("%d ", num[i]);
	}
	printf("\n");
}


void shellSort(int num[], int n) {
	int i, j, gap;
	for (gap = n / 2; gap > 0; gap /= 2) {
		for (i = gap; i < n; i++) {
			for (j = i - gap; j >= 0 && num[j] > num[j + gap]; j -= gap) {
				swap(num[j], num[j + gap]);
			}
		}
	}
}



int main() {

	int num[] = {12, 1, 34, 33, 56, 7};
	shellSort(num, 6);
	print(num, 6);
	return 0;
}
