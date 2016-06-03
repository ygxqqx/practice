#include "string.h"
#include "stdio.h"
#include "stdlib.h"

//如何一个数组类型
//如何一个数组指针的类型
//如何定义一个指向数组类型的一个指针变量

void main_数组类型基础() {
	//int array[10];
	//如何一个数组类型

	typedef int (MyArrayType)[10];

	MyArrayType myArray; ////int array[10];
	myArray[0] = 1;

	{
		//如何一个数组指针的类型
		int array2[10];
		typedef int (*PMyArrayType)[10];
		PMyArrayType  pmyArray;
		pmyArray = &pmyArray;
		(*pmyArray)[0] = 11;

		{
			 int a = 10;
			 int *p = NULL;
			 p = &a;
		}
	}

	{
		int array3[10];
		int (*pM)[10]; //定义了一个指针变量，告诉c编译器给我分配4个字节的内存，，这个指针变量指向一个数组。
		//言外之意是：pM++会后移一个数组单位。。。。（4*10）个字节

		pM = &array3;
		(*pM)[0] = 12;
		printf("%d \n",array3[0] );

	}

	system("pause");
}

//定义函数类型
//定义函数指针类型
//定义一个指针函数的指针变量

//test是函数名，函数名代表函数首地址，函数名就是函数指针 
int test(int a) {
	printf("a:%d", a);
	return 0;
}
void main() {
	//定义一个函数类型。。。
	typedef int (MYFuncType)(int);
	MYFuncType *myfun; //函数指针变量
	test(1); //指向一个函数调用

	{
		myfun = test;
		//通过函数指针变量，可以找到函数入口，可以执行函数
		myfun(2);
	}
	{
		//对函数名字&地址，和不取地址，效果一样。。。。
		//历史遗留原因
		myfun = &test;
		myfun(3);
	}

	{
		int ret = 0;
		//定义了一个函数指针类型
		typedef int (*PMYFuncType)(int);
		PMYFuncType  pMyFuncType;

		pMyFuncType = test;
		ret = pMyFuncType(1);
	}

	{
		//直接定义一个函数指针变量。。。。
		int (*PmyFunc)(int) ; //告诉编译器分配4个字节
		PmyFunc = test;
		PmyFunc(11);

	}
	//printf("myFunc:%d", sizeof(myFunc));
	system("pause");
}