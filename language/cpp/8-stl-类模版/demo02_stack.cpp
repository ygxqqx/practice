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


void main21()
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

struct Teacher
{
	char name[100];
	int age;
};

void main23()
{
	//�����������࣬��������int
	stack<Teacher> s;

	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;

	s.push(t1);
	s.push(t2);
	s.push(t3);
	
	//����ջ������Ԫ�أ�����Ҫһ��һ���ĵ���Ԫ��
	while(!s.empty())
	{
		//��ȡջ��Ԫ��
		Teacher tmp = s.top();

		//����ջԪ��
		s.pop();
		printf("tmp:%d ", tmp.age);
	}
	printf("\n");
	//printStack(s);


	system("pause");
}

void main()
{
	//�����������࣬��������int
	stack<Teacher *> s;

	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;

	s.push(&t1);
	s.push(&t2);
	s.push(&t3);

	//����ջ������Ԫ�أ�����Ҫһ��һ���ĵ���Ԫ��
	while(!s.empty())
	{
		//��ȡջ��Ԫ��
		Teacher *tmp = s.top();

		//����ջԪ��
		s.pop();
		printf("tmp:%d ", tmp->age);
	}
	printf("\n");
	//printStack(s);


	system("pause");
}