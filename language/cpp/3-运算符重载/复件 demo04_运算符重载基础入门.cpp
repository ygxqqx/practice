#include "iostream"
using namespace std;

//a + bi //复数
class Complex
{
public:
	friend Complex operator+(Complex &c1, Complex &c2);
	Complex(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	void printCom()
	{
		cout<<a<<" + "<<b<<"i "<<endl;
	}

private:
	int a;
	int b;
};

/*
//通过全局函数完成对象加
Complex add(Complex &c1, Complex &c2)
{
	Complex c3(c1.a + c2.a, c1.b+c2.b);
	return c3;
}
*/
Complex operator+(Complex &c1, Complex &c2)
{
	Complex c3(c1.a + c2.a, c1.b+c2.b);
	return c3;
}
void main()
{
	{
		int a = 0, b = 0;
		int c = a + b;
		//对于基础类型，编译已经知道如何进行加减
	}
	Complex c1(1, 2), c2(3, 4);
	//为什么要有运算符重载
	//原因 Complex是用户自定义类型。。编译器根本不知道如何进行加减。。。
	//编译器给你提供了一种机制，让用户自己去完成，自定义类型的加减操作。。。。。
	//这个机制就是运算符重载机制

	//Complex c3 = c1 + c2;

	//Complex c3 = add(c1, c2);
	//Complex c3 = operator+(c1, c2);


	Complex c3 = c1 + c2;
	c3.printCom();


	system("pause");
}