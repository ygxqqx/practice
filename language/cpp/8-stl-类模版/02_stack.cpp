#include "iostream"
#include "stack"
using namespace std;

void printStack(stack<int> &s )
{
	//����ջ������Ԫ�أ�����Ҫһ��һ���ĵ���Ԫ��
	while(!s.empty())
	{
		//��ȡջ��Ԫ��
		int tmp = s.top();

		//����ջԪ��
		s.pop();
		printf("tmp:%d ", tmp);

	}
}
void main()
{
	//�����������࣬��������int
	stack<int> s;

	for (int i=0; i<5; i++)
	{
		s.push(i+1);
	}

	//����ջ������Ԫ�أ�����Ҫһ��һ���ĵ���Ԫ��
	while(!s.empty())
	{
		//��ȡջ��Ԫ��
		int tmp = s.top();
		
		//����ջԪ��
		s.pop();
		printf("tmp:%d ", tmp);
	}
	printf("\n");
	printStack(s);

	
	system("pause");
}