#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int printAarray(char **pArray, int num) {
	int i = 0;
	
	if (pArray == NULL) {
		return -1;
	}

	for (i=0; i<num; i++) {
		printf("%s \n", pArray[i]);
	}

	return 0;
}

int sortArray(char **pArray, int num) {
	char *tmp = NULL;
	int i = 0, j = 0;
	
	if (pArray == NULL) {
		return -1;
	}
	for (i=0; i<num; i++) {
		for (j=i+1; j<num; j++) {
			if (strcmp(pArray[i], pArray[j]) > 0) {
				//交换的是数组元素 数组元素是指针
				tmp = pArray[i];
				pArray[i] = pArray[j];
				pArray[j] = tmp;
			}
		}
	}
}
void main() {
	char *tmp = NULL;
	int i = 0, j = 0;
	//二级指针第一种内存模型
	//首先考虑它是一个数组，指针数组，====》只不过每一个元素是指针而已。
	//【】优先级高 
	//打印数组 排序排序这个数组、、、、指针做函数参数
	char * myArray[] = {"bbbbb", "aaaa", "ccccc", "1111111"};

	printf("排序之前\n");
	printAarray(myArray, 4);

	sortArray(myArray, 4);


	printf("排序之后\n");
	printAarray(myArray, 4);

	system("pause");
}