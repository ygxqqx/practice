

#include "iostream"
#include "vector"
using namespace std;

// vector<int> &c 和数组做函数参数区别
//数组做函数 会退化为指针
//类，类有封装概念，突破了函数的概念。。。（封装了属性和方法）

void printfV(vector<int> &c)
{
	int size = c.size();
	for (int i=0; i<size; i++)
	{
		printf("%d ", c[i]);
	}
}

void main01()
{
	//vector是一个模板类。。在使用模板类的时候，需要指明具体的类型
	//
	vector<int> v1(5);  //相当于 int v1[5];

	//vector<char> v1(5);  //相当于 int v1[5];

	for (int i=0; i<5; i++)
	{
		v1[i] = i+1;
		
	}
	for (int i=0; i<5; i++)
	{
		cout<<v1[i];
	}

	vector<int>v2(20);
	//执行=号操作
	v2 = v1;

	printfV(v2);

	//vector会把20个大小全部初始化。。。。
	vector<int>v3(20);
	v3.push_back(100);
	v3.push_back(101);
	printfV(v3);



	system("pause");
}

struct Teacher
{
	char name[10];
	int age;
};

void main02()
{
	//vector是一个模板类。。在使用模板类的时候，需要指明具体的类型
	//
	Teacher t1, t2, t3;
	t1.age = 11;
	t2.age = 22;
	t3.age = 33;
	vector<Teacher> v1(5);  //相当于 int v1[5];
	v1[0] = t1;
	v1[1] = t2;
	v1[2] = t3;

	printf("age:%d \n", v1[0].age);


	system("pause");
}


void main()
{
	//vector是一个模板类。。在使用模板类的时候，需要指明具体的类型
	//
	Teacher t1, t2, t3;
	t1.age = 11;
	t2.age = 22;
	t3.age = 33;
	vector<Teacher *> v1(5);  //相当于 int v1[5];
	v1[0] = &t1;
	v1[1] = &t2;
	v1[2] = &t3;

	for (int i=0; i<v1.size(); i++)
	{
		Teacher *tmp = v1[i];
		if (tmp != NULL)
		{
			printf("age:%d", tmp->age);
		}
	}
	system("pause");
}