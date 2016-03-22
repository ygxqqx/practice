#include "iostream"
using namespace std;

class Test
{
public:
	Test(int a, int b) //有参构造函数
	{
		this->a = a;
		this->b = b;
	}
	int getA()
	{
		return a;
	}
	int getB()
	{
		return b;
	}
public:
	Test& add(Test &t2) //*this
	{
		this->a = this->a + t2.getA();
		this->b = this->b + t2.getB();
		return *this; //*操作让this指针回到元素状态
	}

	Test add2(Test &t2) //*this
	{
		Test t3(this->a+t2.getA(), this->b + t2.getB()) ;//调用了构造器，初始化了Test
		return t3;//返回Test对象
	}
public:
	void printAB()
	{
		cout<<"a:"<<a<<"b:"<<b<<endl;
	}
protected:
private:
	int a;
	int b;
};

//全局函数
//如果把全局函数转成成员函数，少了一个操作数，通过this指针，被隐藏。
Test add(Test &t1, Test &t2)
{
	Test t3(t1.getA()+t2.getA(), t1.getB() + t2.getB()) ;//构造一个Test对象，并返回。
	return t3;//返回的是t3对象，赋值给匿名对象。
}

//把成员函数转成全局函数，需要多一个参数。。。。
void printAB(Test *pthis)
{
	cout<<"a:"<<pthis->getA()<<"b:"<<pthis->getB()<<endl;
}
void main()
{
	Test t1(1, 2); //Test(&t1, 1, 2);
	Test t2(3, 4);
	Test t3 = add(t1, t2);

	t1.add(t2); //---->add(&t1, t2);
	t1.printAB();

	system("pause");
}