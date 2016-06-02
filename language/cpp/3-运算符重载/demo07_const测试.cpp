#include "iostream"
using namespace std;

//C 
class Test {
public:
protected:
private:
	int a;
	const int A() { //const // ====>int A(const this)
		//观点1:const是修饰a,但是通过测试,我们发现,b++也不能编译通过
		//这说明:const把a 和 b都修饰了.......

		//剖析:因为this作为函数的第一个参数,被隐藏......const没有地方放......
		//
		//const是修饰this

		a++;
		//b++;
		return a; 
	}
	void A(int val) {

		a = val; 
	}

	int BBB() {
		
		return a;
	}

	int b;
};


int Aaaaa(const Test *pthis) {

	return 10; 
}
void main() {

	Test t1;
	system("pause");
}
