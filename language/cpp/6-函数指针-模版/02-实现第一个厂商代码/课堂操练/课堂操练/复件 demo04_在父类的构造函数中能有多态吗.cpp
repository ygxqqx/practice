#include "iostream"
using namespace std;

//����
//ʵ�ַ���3
//��̬��ԭ�� 
//

class Parent
{
public:
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
	void print()
	{
		cout<<"���ຯ��"<<endl;
	}
protected:
private:
	int b ;
};


void main()
{

	//Parent p1; //������ط������������Ѿ���ǰ���֡������������������麯����Ķ�����ǰ����vptrָ�롣��
	Child c1;


	system("pause");
}