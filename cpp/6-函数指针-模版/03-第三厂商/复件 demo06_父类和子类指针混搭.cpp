#include "iostream"
using namespace std;



class Parent01
{
protected:
	int i;
	int		j;
public:
	virtual void f()
	{
		cout<<"Parent01::f"<<endl;
	}
};

//一次偶然的成功，比必然的失败更可怕
class Child01 : public Parent01
{	
public:
	//int k;
public:
	Child01(int i, int j)
	{
		printf("Child01:...do\n");
	}

	virtual void f()
	{
		printf("Child01::f()...do\n");
	}
};

void howToF(Parent01 *pBase)
{
	pBase->f();
	
}


int main()
{
	int i = 0;
	Parent01* p = NULL;
	Child01* c = NULL;


	//可以使用赋值兼容性原则，是用在多态的地方
	//不要轻易通过父类指针p++,来执行函数操作
	//问题的本质 子类指针 和父类指针 步长可能不一样。。。
	Child01 ca[3] = {Child01(1, 2), Child01(3, 4), Child01(5, 6)};


	p = ca; //第一个子类对象赋值给p，p是基类指针，
	c = ca;

	p->f(); //有多态发生
	//c->f(); //

	p++;
	//c++;
	
	p->f();//有多态发生
 	//c->f();

// 	for (i=0; i<3; i++)
// 	{
// 		howToF(&(ca[i]));
// 	}


	system("pause");
	return 0;
}

