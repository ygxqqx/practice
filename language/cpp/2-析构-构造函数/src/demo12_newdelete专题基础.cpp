#include "iostream"
using namespace std;

//1 new delete 操作符号 c++的关键字
//malloc free函数

//2 new 在堆上分配内存  delete 
//分配基础类型 、分配数组类型、分配对象

//3

void main121()
{
	//new基础类型
	int *p = (int *)malloc(sizeof(int)); 
	free(p);

	int *p2 = new int; //相当于上面的

	*p2 = 101;
	printf("*p2:%d \n", *p2);
	delete p2;

	//分配内存的同时，初始化
	int *p3 = new int(100);
	delete p3;
	system("pause");
}

void main122()
{
	//new数组
	int *p = (int *)malloc(10*sizeof(int));  //int a[10];
	p[0] = 1;
	free(p);

	//
	int *p2 = new int[10] ;//int a[10];
	p2[0] = 1;
	p2[1] = 2;

	delete [] p2;

	system("pause");
}

class Test
{
public:
	Test(int mya, int myb)
	{
		a = mya;
		b = myb;
		cout<<"构造函数，我被调用了"<<endl;
	}
	~Test()
	{
		cout<<"析构函数，我被调用了"<<endl;
	}
	int getA()
	{
		return a;
	}
protected:
private:
	int a;
	int b;
};

int getTestObj(Test **my)
{
		Test *p = new Test(1, 2);
		*my = p;
		return 0;
}

void main()
{
	Test t1(1, 2);//在临时区分配内存
	//new + 类型  返回一个 内存首地址
	//new操作符也会自动的调用这个类的构造函数 、
	//delete自动的调用这个类的析构函数 
	//相当于我们程序员可以手工控制类的对象的生命周期
	Test *p = new Test(1, 2);
	cout<<p->getA()<<endl;
	delete p;


	getTestObj(&p);
	delete p;



	system("pause");
}