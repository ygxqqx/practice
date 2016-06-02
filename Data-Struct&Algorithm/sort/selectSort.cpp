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


void selectSort(int num[], int n) {
	
	int mix;
	for (int i=0; i<n; ++i) {
		mix = i;
		for (int j=i+1; j<n; ++j) {
			if (num[j]<num[mix]) {
				mix = j;
			}
		}
		if (i != mix) {
			swap(num[mix], num[i]);
		}
	}
}



int main() {

	int num[] = {12, 1, 34, 33, 56, 7};
	selectSort(num, 6);
	print(num, 6);
	return 0;
}
