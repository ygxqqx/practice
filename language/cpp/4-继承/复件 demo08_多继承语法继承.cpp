#include "iostream"
using namespace std;

class Base1
{
public:
	Base1()
	{
		b1 = 1;
	}
	int b1;
protected:
private:
};

class Base2
{
public:
	Base2()
	{
		b2 = 2;
	}
	int b2;
protected:
private:
};

class Child : public Base1, public Base2
{
public:
	Child()
	{
		cout<<"zilei"<<endl;
	}
	void printB()
	{
		cout<<"b1"<<b1<<"b2"<<b2<<endl;
	}
protected:
private:
};

void main()
{
	Child c1;
	c1.printB();
	system("pause");
}