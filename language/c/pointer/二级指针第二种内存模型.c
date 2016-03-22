
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

/*
int printfArray(int a[10]);
int printfArray(int a[]);
int printfArray(int *a);
*/

int printAarray02(char pArray[10][30], int num)
{
	int i = 0;

	if (pArray == NULL)
	{
		return -1;
	}

	for (i=0; i<num; i++)
	{
		printf("%s \n", pArray[i]);
	}

	return 0;
}

int sortArray02(char bufArray[10][30], int num)
{
	int i = 0, j = 0;
	char tmpBuf[30];
	for (i=0; i<num; i++)
	{
		for (j=i+1; j<num; j++)
		{
			if (strcmp(bufArray[i], bufArray[j]) > 0)
			{
				strcpy(tmpBuf, bufArray[i]);
				strcpy(bufArray[i], bufArray[j]);
				strcpy(bufArray[j], tmpBuf);
			}
		}
	}
}
void main()
{
	int i = 0, j = 0;
	char tmpBuf[30];
	
	//打印 排序 ，再打印  //二维数组
	char bufArray[10][30] =  {"ccccc", "aaaa", "bbbb","11111"};

	printf("排序之前打印\n");
// 	for (i=0; i<4; i++)
// 	{
// 		printf("%s \n", bufArray[i]); 
// 	}
	printAarray02(bufArray, 4);

	sortArray02(bufArray, 4);


	printf("排序之后打印\n");
	printAarray02(bufArray, 4);

	system("pause");
}