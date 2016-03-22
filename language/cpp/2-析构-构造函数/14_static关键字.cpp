#include "iostream"
using namespace std;


class BB
{
public:
	int getC()
	{
		return c;
	}
	void setC(int nyc)
	{
		c = nyc;
		
	}
	 //静态成员函数是属于整个类，
	//在类的静态数据成员函数中，是不能调用具体的对象的变量的属性。。。。（抛砖）
	//不能调用普通成员变量
	static void getMem()
	{
		//cout<<a<<endl;
		cout<<c<<endl;
	}
protected:
private:
	int a;
	int b;
	static int c;
};
 int BB::c = 0;

 //static修饰的变量，是属于类，，所有的对象都能共享用。
void main111()
{
	BB b1;
	BB b2;
	cout<<b2.getC()<<endl;;
	b1.setC(100);
	cout<<b2.getC()<<endl;;

	system("pause");
}

void main()
{
	//调用静态成员函数的方法1
	BB::getMem();

	//调用静态成员函数的方法2
	BB b1;
	b1.getMem();

	system("pause");
}