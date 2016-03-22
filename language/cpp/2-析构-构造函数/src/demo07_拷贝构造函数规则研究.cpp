#include "iostream"
using namespace std;

class Test
{
public:
	//如果你写了copy构造函数，那么编译器不会在提供无参构造函数
	Test(Test &obj)
	{
		cout<<"我是copy构造函数"<<endl;
		//a = 1;
		//b = 2;
	}
	//如果你写了有参或者无参构造函数，那么编译器也不会提供无参构造函数
	Test(int _a, int _b)
	{
		cout<<"我是copy构造函数"<<endl;
		//a = 1;
		//b = 2;
	}
protected:
private:
	int a ;
	int b;
};

void main()
{
	Test t1;
	//Test t2;
	//Test t3 = t2;
	system("pause");
}