#include "string.h"
#include "stdio.h"
#include "stdlib.h"

//子任务写任务的人
int add(int a, int b) {
	int c ;
	c = a + b;
	printf("func add:%d \n", c);
	return c;
}

int add2(int a, int b) {
	int c ;
	c = a + b;
	printf("func add:%d \n", c);
	return c;
}

//调用任务的人
int MyOP(int (*MyAdd)(int, int)) {
	//执行add函数调用有2种方法
	add(1, 2);
	MyAdd(3, 4);
	return 0;
}
//我在声明一个类型，申明一个函数指针类型。。。
typedef int(*PMyFuncType)(int , int);
//函数指针做函数参数的本质。
//1）不光是把函数入口地址给传送给被调用函数。。
//2）同时，函数类型，也做了一个接口的约定。。。。。。（任务类型的约定）
//反映到代码上。。。函数三要素 （参数、返回值）统统的做了一个约定。。。。
//这个就函数指针做函数参数的核心思想。。。

//对比：C++
	//
int MyOP2(PMyFuncType pMyFuncType) {
	//执行add函数调用有2种方法
	add(1, 2);
	pMyFuncType(3, 4);
	return 0;
}

//调用任务的人，，分开了。。。。。。
void main() {

	//定义一个指针变量，函数指针变量
	int (*pAdd)(int , int); 
	//把函数的入口地址复制给。。。。pAdd
	pAdd = add;
	//调用MyOP，要求传送一个函数指针类型。。的变量。。。
	//MyOP(pAdd);
	MyOP2(add2);
	system("pause");
}