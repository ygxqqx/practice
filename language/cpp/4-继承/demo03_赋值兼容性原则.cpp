#include "iostream"
using namespace std;

class Parent {
public:
	void printP() {
		printf("我是爹。。。\n");
	}
protected:
	int a;
	int b;
};

class Child : public Parent {
public:
	Child() {
		a = 0; b = 0; c= 0;
	}
	void printC() {
		printf("我是儿子。。。\n");
	}
protected:
private:
	int c;
};


void howToPrint(Parent *p) {
	p->printP();
}

void howToPrint2(Parent &p) {
	p.printP();
}

//赋值兼容性原则
/*
子类对象可以当作父类对象使用
	子类对象可以直接赋值给父类对象
	子类对象可以直接初始化父类对象
	父类指针可以直接指向子类对象
	父类引用可以直接引用子类对象
*/

void main() {
	Parent p1;
	p1.printP();

	Child c1;
	c1.printC();


	Parent *base = NULL;
	base = &c1;
	
	//可以把子类对象赋给基类指针
	//子类就是一种特殊的父类
	//
	base->printP();


	Parent &myp = c1;
	myp.printP();


	//测试父类指针，做函数参数
	howToPrint(&p1);
	howToPrint(&c1);

	//测试父类引用，做函数参数
	howToPrint2(p1);
	howToPrint2(c1);

	//可以用子类对象来初始化父类对象。。。。

	//这是编译器给我们提供的行为，我们只能顺序
	Parent p3 = c1;
	
	system("pause");
}