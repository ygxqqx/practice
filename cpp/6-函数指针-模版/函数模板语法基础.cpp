#include "iostream"
using namespace std;

/*
//ҵ���ϵһ�����������������һ��
//���������Ͳ�����
void myswap(int &a ,int &b)
{
	int c = a;
	a = b;
	b = c;
}

void myswap2(char &a ,char &b)
{
	char c = a;
	a = b;
	b = c;
}


void main01()
{
	int a1 = 1;
	int b1 = 2;
	char a2 = 'a';
	char b2 = 'b';
	myswap(a1, b1);
	printf("a1:%d b1:%d \n", a1, b1);

	myswap2(a2, b2);
	printf("a2:%d b2:%d \n", a2, b2);
	
	system("pause");
}
*/


//template�ؼ��ָ���c++��������������Ҫ���з��ͱ�̣�
//typename ����c++��������TΪ�������ͣ��������㲻Ҫ�ұ�����������
//TΪ�������ͣ�TΪ�������Ͳ����������ѡ���������
//int char double 
template<typename T>
void myswap3(T &a, T &b)
{
	T t = a;
	a = b;
	b = t;
};

void main()
{
	//���ͱ�̺�����ʹ�÷�����2��
	int x = 1;
	int y = 2;
	//�Զ������Ƶ�����
	//myswap3(x, y);

	//�������͵���
	myswap3<int>(x, y);

	char c1 = 'a';
	char c2 = 'b';
	myswap3<char>(c1, c2);
	system("pause");
}