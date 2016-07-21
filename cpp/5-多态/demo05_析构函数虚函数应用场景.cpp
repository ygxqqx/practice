#include "iostream"
using namespace std;
//现象
//实现方法3
//多态的原理 
//

class Parent {
public:
	//在父类的构造函数里面，调用虚函数，不会产生多态。。
	//言外之意：不会调用子类的虚函数。。。。
	Parent(int a = 0) {
		//print(); //
		this->a = a;
	}
	virtual ~Parent() {
		cout<<"调用父类虚析构函数"<<endl;
	}

	void printAbc() {
		printf("父类abc");
	}
	//第一个动手脚的地方 编译器应该对这个虚函数特殊处理。。。。
	virtual void print() {
		cout<<"父类函数"<<endl;
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
	~Child() {
		cout<<"调用子类的虚析构函数"<<endl;
	}
	virtual void print() {
		cout<<"子类函数"<<endl;
	}
protected:
private:
	int b ;
};

//在父类中声明虚析构函数的原因
//通过父类指针，把所有的子类析构函数都执行一遍。。。
//
void howtoDel(Parent *pbase) {
	delete pbase;
}

void mainobj() {
	Parent *p1 = new Parent();
	p1->print();
	delete p1;
}

void main() {
	Child *pc1 = new Child();

	howtoDel(pc1);
	//mainobj();
	system("pause");
}