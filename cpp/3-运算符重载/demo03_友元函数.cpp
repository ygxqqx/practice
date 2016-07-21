#include "iostream"
using namespace std;

class A1 {
public:
	A1() {

		a1 = 100;
		a2 = 200;
	}
	int getA1() {

		return this->a1;
	}
	//声明一个友元函数
	friend void setA1(A1 *p, int a1); //什么这个函数是这个类的好朋友
	
protected:
private:
	int a1;
	int a2;
};

void setA1(A1 *p, int a1) {

	p->a1 = a1;
}
//friend 破坏了类的封装性。。。。
//friend关键字是一个关系户
//why 无奈之际 java class
//java---》1.class==》class==>java类
//java类的反射 sun jdk api

//cc++ 1预编译gcc -E 2汇编 gcc -i 3编译gcc -c 3、链接ld ===》汇编代码
//friend 
//应用场景。。。。。
//const关键字 冒牌货c
//register
//typedef 混号王 

void main11() {

	A1 mya1;
	cout<<mya1.getA1()<<endl;
	setA1(&mya1, 300);
	cout<<mya1.getA1()<<endl;

	system("pause");
}

class A {
	//b是a的好朋友	
	friend class B;
public:
	void display() {

		cout<<x<<endl;
	}

protected:
private:
	int x;
};

class B {
public:
	void setA(int x) {

		Aobj.x = x;
	}
	void printA() {

		cout<<Aobj.x<<endl;
	}
protected:
private:
	A Aobj;

};

void main() {
	
	B b1;
	b1.setA(100);
	b1.printA();
	system("pause");
}