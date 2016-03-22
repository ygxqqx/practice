#include "iostream"
#include "stack"
using namespace std;

void printStack(stack<int> &s )
{
	//遍历栈的所有元素，必须要一个一个的弹出元素
	while(!s.empty())
	{
		//获取栈顶元素
		int tmp = s.top();

		//弹出栈元素
		s.pop();
		printf("tmp:%d ", tmp);

	}
}


void main21()
{
	//定义了容器类，具体类型int
	stack<int> s;

	for (int i=0; i<5; i++)
	{
		s.push(i+1);
	}

	//遍历栈的所有元素，必须要一个一个的弹出元素
	while(!s.empty())
	{
		//获取栈顶元素
		int tmp = s.top();
		
		//弹出栈元素
		s.pop();
		printf("tmp:%d ", tmp);
	}
	printf("\n");
	printStack(s);

	
	system("pause");
}

struct Teacher
{
	char name[100];
	int age;
};

void main23()
{
	//定义了容器类，具体类型int
	stack<Teacher> s;

	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;

	s.push(t1);
	s.push(t2);
	s.push(t3);
	
	//遍历栈的所有元素，必须要一个一个的弹出元素
	while(!s.empty())
	{
		//获取栈顶元素
		Teacher tmp = s.top();

		//弹出栈元素
		s.pop();
		printf("tmp:%d ", tmp.age);
	}
	printf("\n");
	//printStack(s);


	system("pause");
}

void main()
{
	//定义了容器类，具体类型int
	stack<Teacher *> s;

	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;

	s.push(&t1);
	s.push(&t2);
	s.push(&t3);

	//遍历栈的所有元素，必须要一个一个的弹出元素
	while(!s.empty())
	{
		//获取栈顶元素
		Teacher *tmp = s.top();

		//弹出栈元素
		s.pop();
		printf("tmp:%d ", tmp->age);
	}
	printf("\n");
	//printStack(s);


	system("pause");
}