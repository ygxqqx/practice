#include <stdio.h>
#include<stdlib.h>

void swap(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}

void bubbleSort(int n, int *arr) {

	int i = 0, j;
	bool flag = true;
	while (flag) {

		flag = false;
		for (j=1; j<n-i; ++j) {
			if (arr[j-1]<arr[j]) {
				swap(arr[j-1], arr[j]);
				flag = true;
			}
		}
		++i;
	}
}



int main(int argc, char const *argv[]) {
	
	int num, i;
	printf("please enter num:");
	scanf("%d", &num);
	int *arr = (int*)malloc(num*sizeof(int));

	printf("please enter %d number:", num);
	for (i = 0; i < num; ++i) {
		scanf("%d", arr+i);
	}

	bubbleSort(num, arr);

	for (i = 0; i < num; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

