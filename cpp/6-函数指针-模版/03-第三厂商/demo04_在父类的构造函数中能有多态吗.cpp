#include "iostream"
using namespace std;

//����
//ʵ�ַ���3
//��̬��ԭ�� 
//

class Parent
{
public:
	//�ڸ���Ĺ��캯�����棬�����麯�������������̬����
	//����֮�⣺�������������麯����������
	Parent(int a = 0)
	{
		print(); //
		this->a = a;
	}

	 void printAbc()
	{
		printf("����abc");
	}
	//��һ�����ֽŵĵط� ������Ӧ�ö�����麯�����⴦��������
	virtual void print()
	{
		cout<<"���ຯ��"<<endl;
	}
protected:
private:
	int a;
};

class Child : public Parent
{
public:
	Child(int b = 0)
	{
		this->b = b;
	}
	virtual void print()
	{
		cout<<"���ຯ��"<<endl;
	}
protected:
private:
	int b ;
};


void main()
{
	Child c1;
	system("pause");
}