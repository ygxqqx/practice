#include "stdio.h"
#include "string.h"
#include "stdlib.h"


void main1111()
{
	char* tmp = NULL;
	int i = 0, j = 0;
	//二级指针第一种内存模型
	//首先考虑它是一个数组，指针数组，====》只不过每一个元素是指针而已。
	//【】优先级高 
	//打印数组 排序排序这个数组、、、、指针做函数参数
	//
	char * myArray[4] = {"bbbbb", "aaaa", "ccccc", "1111111"};
	sizeof(myArray); //myArray是二级指针和int a[10]一级指针不一样
	
	{
		int num1 = sizeof(myArray)/sizeof(myArray[0]);
		int num2 = sizeof(myArray)/sizeof(*myArray);
		printf("num1:%d, num2:%d \n", num1, num2);
	}

	printf("排序之前\n");
	for (i=0; i<4; i++)
	{
		printf("%s \n", myArray[i]);
	}

	for (i=0; i<4; i++)
	{
		for (j=i+1; j<4; j++)
		{
			if (strcmp(myArray[i], myArray[j]) > 0)
			{
				//交换的是数组元素 数组元素是指针
				tmp = myArray[i];
				myArray[i] = myArray[j];
				myArray[j] = tmp;
			}
		}
	}

	printf("排序之后\n");
	for (i=0; i<4; i++)
	{
		printf("%s \n", myArray[i]);
	}

	system("pause");
}

int main()
{
	int a[10]; //a代表数组首元素的地址 
	main1111();
	printf("sizeof(a[10]):%d\n" , sizeof(a)); //4
	printf("&a:%d\n" , sizeof(&a)); //40

}