#include "iostream"
using namespace std;

//现象
//实现方法3
//多态的原理 
//

class Parent
{
public:
	//在父类的构造函数里面，调用虚函数，不会产生多态。。
	//言外之意：不会调用子类的虚函数。。。。
	Parent(int a = 0)
	{
		print(); //
		this->a = a;
	}

	 void printAbc()
	{
		printf("父类abc");
	}
	//第一个动手脚的地方 编译器应该对这个虚函数特殊处理。。。。
	virtual void print()
	{
		cout<<"父类函数"<<endl;
	}
protected:
private:
	int a;
};

class Child : public Parent
{
public:
	Child(int b = 0)
	{
		this->b = b;
	}
	virtual void print()
	{
		cout<<"子类函数"<<endl;
	}
protected:
private:
	int b ;
};


void main()
{
	Child c1;
	system("pause");
}