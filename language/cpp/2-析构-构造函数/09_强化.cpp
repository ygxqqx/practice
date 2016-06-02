/*
1 C++中提供了初始化列表对成员变量进行初始化
2 使用初始化列表出现原因:
1.必须这样做:
	如果我们有一个类成员,它本身是一个类或者是一个结构,
	而且这个成员它只有一个带参数的构造函数,
	而没有默认构造函数,这时要对这个类成员进行初始化,
	就必须调用这个类成员的带参数的构造函数,
	如果没有初始化列表,那么他将无法完成第一步,就会报错.

2.  类成员中若有const修饰,必须在对象初始化的时候,给const int m 赋值
	当类成员中含有一个const对象时,或者是一个引用时,
	他们也必须要通过成员初始化列表进行初始化
	因为这两种对象要在声明后马上初始化,而在构造函数中,
	做的是对他们的赋值,这样是不被允许的.
*/

//总结 构造和析构的调用顺序

#include "iostream"
using namespace std;

class ABC {
public:
	ABC(int a, int b, int c) {
		this->a = a;
		this->b = b;
		this->c = c;
		printf("a:%d,b:%d,c:%d \n", a, b, c);
		printf("ABC construct ..\n");
	}
	~ABC() {
		printf("a:%d,b:%d,c:%d \n", a, b, c);
		printf("~ABC() ..\n");
	}
protected:
private:
	int a;
	int b;
	int c;
};


class MyD {
public:

	MyD():abc1(1,2,3),abc2(4,5,6),m(100) {
		cout<<"MyD()"<<endl;
	}
	~MyD() {
		cout<<"~MyD()"<<endl;
	}

protected:
private:
	ABC abc1; //c++编译器不知道如何构造abc1
	ABC abc2;
	const int m;
};


int run() {

	MyD myD;
	return 0;
}

int main() {

	run();
	system("pause");
	return 0;
}
