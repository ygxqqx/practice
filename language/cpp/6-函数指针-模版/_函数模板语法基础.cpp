#include "iostream"
using namespace std;

/*
//业务关系一样，处理的数据类型一样
//让数据类型参数化
void myswap(int &a ,int &b)
{
	int c = a;
	a = b;
	b = c;
}

void myswap2(char &a ,char &b)
{
	char c = a;
	a = b;
	b = c;
}


void main01()
{
	int a1 = 1;
	int b1 = 2;
	char a2 = 'a';
	char b2 = 'b';
	myswap(a1, b1);
	printf("a1:%d b1:%d \n", a1, b1);

	myswap2(a2, b2);
	printf("a2:%d b2:%d \n", a2, b2);
	
	system("pause");
}
*/


//template关键字告诉c++编译器，现在我要进行泛型编程，
//typename 告诉c++编译器，T为数据类型，，，请你不要乱报错。。。。。
//T为数据类型，T为数据类型参数化，而已。。。。。
//int char double 
template<typename T>
void myswap3(T &a, T &b)
{
	T t = a;
	a = b;
	b = t;
};

void main()
{
	//泛型编程函数的使用方法有2种
	int x = 1;
	int y = 2;
	//自动类型推导，，
	//myswap3(x, y);

	//具体类型调用
	myswap3<int>(x, y);

	char c1 = 'a';
	char c2 = 'b';
	myswap3<char>(c1, c2);
	system("pause");
}