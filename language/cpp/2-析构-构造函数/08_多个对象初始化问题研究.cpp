#include "iostream"
using namespace std;

class A
{
public:
	A(int _a1)
	{
		a1 = _a1;
	}
protected:
private:
	int a1;
};

//构造函数的初始化列表产生原因
//语法现象
class B
{
public:
	B():mya(12),mya2(100)
	{
		;
	}
	//成员变量的初始化顺序与声明的顺序相关，与在初始化列表中的顺序无关
	B(int x, int y):mya(y),mya2(101)
	{
		b1 = x;
	}
protected:
private:
	int b1;
	A mya2;
	A mya;
	
};


void main()
{
	A a1(10);
	B b1(10, 20);
	system("pause");
}