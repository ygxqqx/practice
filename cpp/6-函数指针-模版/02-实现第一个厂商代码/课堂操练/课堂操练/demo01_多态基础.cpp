#include "iostream"
using namespace std;

//现象
//实现方法3
//多态的原理 
//

class Parent
{
public:
	Parent(int a = 0)
	{
		this->a = a;
	}

	virtual void printAbc()
	{

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
	 void print()
	{
		cout<<"子类函数"<<endl;
	}
protected:
private:
	int b ;
};

void howToPrintf(Parent *pBase)
{
	//动手脚的地方2  传来一个子类对象，调用子类的函数，传来一个父类对象，调用父类的函数
	//===》判断Base===》增加判读的条件，===》应该是在你不知道的情况下，增加判断条件
	//====>编译器提前给你加条件。。。。
	//hadle  .......

	//编译器提前布局
	pBase->print();  
}
void main()
{
	
	Parent p1; //在这个地方，，编译器已经提前布局。。。。。给函数有虚函数表的对象，提前加了vptr指针。。
	Child c1;

	howToPrintf(&p1);
	howToPrintf(&c1);


	system("pause");
}