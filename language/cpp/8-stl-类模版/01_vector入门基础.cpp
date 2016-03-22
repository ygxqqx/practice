

#include "iostream"
#include "vector"
using namespace std;

// vector<int> &c ��������������������
//���������� ���˻�Ϊָ��
//�࣬���з�װ���ͻ���˺����ĸ����������װ�����Ժͷ�����

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
	//vector��һ��ģ���ࡣ����ʹ��ģ�����ʱ����Ҫָ�����������
	//
	vector<int> v1(5);  //�൱�� int v1[5];

	//vector<char> v1(5);  //�൱�� int v1[5];

	for (int i=0; i<5; i++)
	{
		v1[i] = i+1;
		
	}
	for (int i=0; i<5; i++)
	{
		cout<<v1[i];
	}

	vector<int>v2(20);
	//ִ��=�Ų���
	v2 = v1;

	printfV(v2);

	//vector���20����Сȫ����ʼ����������
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
	//vector��һ��ģ���ࡣ����ʹ��ģ�����ʱ����Ҫָ�����������
	//
	Teacher t1, t2, t3;
	t1.age = 11;
	t2.age = 22;
	t3.age = 33;
	vector<Teacher> v1(5);  //�൱�� int v1[5];
	v1[0] = t1;
	v1[1] = t2;
	v1[2] = t3;

	printf("age:%d \n", v1[0].age);


	system("pause");
}


void main()
{
	//vector��һ��ģ���ࡣ����ʹ��ģ�����ʱ����Ҫָ�����������
	//
	Teacher t1, t2, t3;
	t1.age = 11;
	t2.age = 22;
	t3.age = 33;
	vector<Teacher *> v1(5);  //�൱�� int v1[5];
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