#include "stdio.h"
#include "string.h"
#include "stdlib.h"



int printAarray03(char **  pArray, int num) {
	int i = 0;

	if (pArray == NULL) {
		return -1;
	}

	for (i=0; i<num; i++) {
		printf("%s \n", pArray[i]);
	}

	return 0;
}

int sortArray03(char **pArray, int num) {
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
	int i = 0, j = 0;
	char **pArray = NULL;
	char *tmp = NULL;
	//构造内存
	pArray = (char **)malloc(100*sizeof(char *)); //int pArray[100];
	pArray[0] = (char *)malloc(12*sizeof(char)); //char buf[12];
	pArray[1] = (char *)malloc(200*sizeof(char)); //char buf[200];
	pArray[2] = (char *)malloc(200*sizeof(char)); //char buf[200];
	pArray[3] = (char *)malloc(200*sizeof(char)); //char buf[200];

	strcpy(pArray[0], "cccccc");
	strcpy(pArray[1], "aaaa");
	strcpy(pArray[2], "bbbb");
	strcpy(pArray[3], "11111");

	
	 printAarray03(pArray, 4);

// 	for (i=0; i<4; i++)
// 	{
// 		for (j=i+1; j<4; j++)
// 		{
// 			if ( strcmp(pArray[i], pArray[j])  > 0)
// 			{
// 				tmp = pArray[i] ;
// 				pArray[i] = pArray[j];
// 				pArray[j] = tmp;
// 			}
// 		}
// 	}
	sortArray03(pArray, 4);

	printf("第三种内存排序之后\n");
	printAarray03(pArray, 4);


	//释放内存
	for (i=0; i<4; i++) {
		if (pArray[i] != NULL) {
			free(pArray[i]);
		}
	}
	if (pArray != NULL) {
		free(pArray);
	}




	system("pause");
}