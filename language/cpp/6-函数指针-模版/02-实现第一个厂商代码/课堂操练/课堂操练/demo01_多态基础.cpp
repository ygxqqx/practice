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
		this->a = a;
	}

	virtual void printAbc()
	{

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

void howToPrintf(Parent *pBase)
{
	//���ֽŵĵط�2  ����һ��������󣬵�������ĺ���������һ��������󣬵��ø���ĺ���
	//===���ж�Base===�������ж���������===��Ӧ�������㲻֪��������£������ж�����
	//====>��������ǰ�����������������
	//hadle  .......

	//��������ǰ����
	pBase->print();  
}
void main()
{
	
	Parent p1; //������ط������������Ѿ���ǰ���֡������������������麯����Ķ�����ǰ����vptrָ�롣��
	Child c1;

	howToPrintf(&p1);
	howToPrintf(&c1);


	system("pause");
}