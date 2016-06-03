#include "iostream"
#include "cstdlib"
using namespace std;
/*
函数模板的深入理解

	― 编译器并不是把函数模板处理成能够处理任意类型的函数
	― 编译器从函数模板通过具体类型产生不同的函数
	― 编译器会对函数模板进行两次编译
	―在声明的地方对模板代码本身进行编译
	―在调用的地方对参数替换后的代码进行编译
*/

//template告诉编译器，这里开始进行泛型编程
//typename告诉编译器，类型名称为T 编译器你看到类型T 不要乱报错。。。。
//T为类型，类型参数化而已
template<typename T>
void swap2(T &a, T &b) {
	T t = a;
	a = b;
	b = t;
}

void swap2(int &a, int &b) {
	T t = a;
	a = b;
	b = t;
}

void swap2(float &a, float &b) {
	T t = a;
	a = b;
	b = t;
}

int main() {
	int x = 1;
	int y = 2;
	//泛型编程的调用方式分为两种
	//自动类型 推导调用
	swap2<int>(x, y);
	//printf("\n%d, %d", x, y);
	float x1 = 1.0;
	float y1 = 2.0;
	//具体类 显示调用
	swap2<float>(x1, y1);
	//printf("\n%f, %f", x1, y1);
	cout<<"hello...."<<endl;
	system("pause");
	return 0;
}