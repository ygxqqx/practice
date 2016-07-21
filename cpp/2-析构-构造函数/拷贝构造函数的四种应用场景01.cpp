#include "iostream"
using namespace std;

class AA {
public:
	AA() {
		//无参构造函数 默认构造函数	
		cout<<"我是构造函数，自动被调用了"<<endl;
	}
	AA(int _a) {
		//无参构造函数 默认构造函数	
		a = _a;
	}

	~AA() {

		cout<<"我是析构函数，自动被调用了"<<endl;
	}
	void getA() {

		printf("a:%d \n", a);
	}
protected:
private:
	int a;
};

//单独搭建一个舞台
void ObjPlay01() {

	AA a1; //变量定义
	
	//赋值构造函数的第一个应用场景
	//我用对象1 初始化 对象2 
	AA a2 = a1; //定义变量并初始化

	a2 = a1; //用a1来=号给a2 编译器给我们提供的浅copy
}

//单独搭建一个舞台
void ObjPlay02() {

	AA a1(10); //变量定义

	//赋值构造函数的第一个应用场景
	//我用对象1 初始化 对象2 
	AA a2(a1); //定义变量并初始化

	//a2 = a1; //用a1来=号给a2 编译器给我们提供的浅copy
	a2.getA();
}

void main() {
	
	ObjPlay02();
	system("pause");
}