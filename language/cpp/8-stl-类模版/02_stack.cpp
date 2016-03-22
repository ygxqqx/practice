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
void main()
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