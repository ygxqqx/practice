#include "iostream"
using namespace std;

class A
{
public:
	A(int _a1)
	{
		a1 = _a1;
	}
protected:
private:
	int a1;
};

//���캯���ĳ�ʼ���б����ԭ��
//�﷨����
class B
{
public:
	B():mya(12),mya2(100)
	{
		;
	}
	//��Ա�����ĳ�ʼ��˳����������˳����أ����ڳ�ʼ���б��е�˳���޹�
	B(int x, int y):mya(y),mya2(101)
	{
		b1 = x;
	}
protected:
private:
	int b1;
	A mya2;
	A mya;
	
};


void main()
{
	A a1(10);
	B b1(10, 20);
	system("pause");
}