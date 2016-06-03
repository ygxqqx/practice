#include "iostream"
using namespace std;

//定义一个子类和一个父类
class Parent {

public:
	Parent(int a = 0) {

		this->a = a;
	}
	virtual void print() {

		cout<<"父类a:"<<a<<endl;
	}
protected:
private:
	int a; 
};

class Child : public Parent {

public:
	Child(int b = 0) {

		this->b = b;
	}
	void print() {

		cout<<"子类b:"<<b<<endl;
	}
protected:
private:
	int  b;
};


//面向对象新需求
//如果我传一个父类对象，执行父类的print函数
//如果我传一个子类对象，执行子类的printf函数


//现象产生的原因
//赋值兼容性原则遇上函数重写 出现的一个现象
//1 没有理由保存
//2 对被调用函数来讲，
//3 在编译器编译期间，我就确定了，这个函数的参数是p，是Parent类型的。。。
//静态链编
void HowToPrint1(Parent *p) {

	p->print(); //一句话，有多种效果，有多种表现形态把。。。//这个功能的就是多态
}
void HowToPrint2(Parent &myp) {

	myp.print();
}
void main() {

	Parent p1;
	Child c1;
	/*
	p1.print();
	c1.print();

	
	Parent *p = NULL;
	p = &p1;
	p->print(); //调用父类的打印函数

	////赋值兼容性原则 遇上 同名函数的时候 
	p = &c1; 
	p->print(); //

	Parent &myp = c1;
	myp.print(); 
	*/


	HowToPrint1(&p1);
	HowToPrint1(&c1);

	HowToPrint2(p1);
	HowToPrint2(c1);

	system("pause");
}