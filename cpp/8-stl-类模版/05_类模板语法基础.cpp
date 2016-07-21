#include "iostream"
using namespace std;

//类模板的创建
//类中的属性，，类型参数化
//我们把数据类型，进一步 抽象化。。。
//抽象化的数据类型，不能直接使用。。
template<typename T>
class A {
public:

	//注意函数函数声明和函数实现的区别
	//函数申明
	A(int a) {
		this->a = a;
	}

	~A() {

	}
	T getA() {
		return a;
	}
	void setA(T a) {
	 this->a = a;
	}
protected:
private:
	 T a;
};

/*

void printA(A<int> *p)
{
	cout<<"打印a："<<p->getA()<<endl;
}

void printA2(A<char> *p)
{
	cout<<"打印a："<<p->getA()<<endl;
}
void main51()
{

	A<char> a1;
	A<int> b1(19);
	b1.setA(10);
	cout<<"打印a："<<b1.getA()<<endl;
	//printA(&b1);

	system("pause");
}
*/



class B {
public:
protected:
private:
	int b;
};

//a是一个抽象化的类型（参数化的类型），，不能拿来直接使用
class C : public A<int> {
public:
	C(int c, int a) : A<int>(a) {
		this->c = c;
	}
protected:
private:
	int c;
};

void printC(C *myc) {
	cout<<myc->getA()<<endl;
}
void main() {

	C  myc(1, 2);
	printC(&myc);
	system("pause");
}
