#include "iostream"
using namespace std;

//类模板的创建
//类中的属性，，类型参数化

//我们把数据类型，进一步 抽象化。。。
//抽象化的数据类型，不能直接使用。。
template<typename T>
class A {
public:
	
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

void printA(A<int> *p) {
	 cout<<"打印a："<<p->getA()<<endl;
}

void printA2(A<char> *p) {
	cout<<"打印a："<<p->getA()<<endl;
}

void main() {
	
	A<char> a1;
	A<int> b1;
	b1.setA(10);
	cout<<"打印a："<<b1.getA()<<endl;
	printA(&b1);
	system("pause");
}