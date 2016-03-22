#include "iostream"
using namespace std;


//抽象一个类
//抽象类
class figure
{
public:
	virtual int showarea() = 0; //纯虚函数
	//int showarea2() = 0;
	//int showarea3() = 0;
};

class Tri : public figure
{
public:
	Tri(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	virtual int showarea()
	{
		cout<<"三角形s"<<a*b/2<<endl;
		return 0;
	}
protected:
private:
	int a;
	int b;
};

class Squre : public figure
{
public:
	Squre(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	virtual int showarea()
	{
		cout<<"四边形s"<<a*b<<endl;
		return 0;
	}
protected:
private:
	int a;
	int b;
};


//通过抽象类，定义一套接口。。让别人实现你的抽象类的接口定义；。。。
//框架就可以在不做任何改变的情况下，调用后来人写的子类（抽象类的子类）。。
void printS(figure *pbase)
{
	pbase->showarea();
}
void main81()
{
	
	//figure f;
	figure *pbase = NULL;
	Tri tri(10, 2);
	tri.showarea();
	Squre sq(3, 4);
	sq.showarea();

	system("pause");
}

void main()
{

	//figure f;
	figure *pbase = NULL;
	Tri tri(10, 2);
	Squre sq(3, 4);

	printS(&tri);
	printS(&sq);

	system("pause");
}