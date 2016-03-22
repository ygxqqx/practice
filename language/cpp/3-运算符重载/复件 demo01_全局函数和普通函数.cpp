#include "iostream"
using namespace std;

class Test
{
public:
	Test(int a, int b) //�вι��캯��
	{
		this->a = a;
		this->b = b;
	}
	int getA()
	{
		return a;
	}
	int getB()
	{
		return b;
	}
public:
	Test& add(Test &t2) //*this
	{
		this->a = this->a + t2.getA();
		this->b = this->b + t2.getB();
		return *this; //*������thisָ��ص�Ԫ��״̬
	}

	Test add2(Test &t2) //*this
	{
		Test t3(this->a+t2.getA(), this->b + t2.getB()) ;//�����˹���������ʼ����Test
		return t3;//����Test����
	}
public:
	void printAB()
	{
		cout<<"a:"<<a<<"b:"<<b<<endl;
	}
protected:
private:
	int a;
	int b;
};

//ȫ�ֺ���
//�����ȫ�ֺ���ת�ɳ�Ա����������һ����������ͨ��thisָ�룬�����ء�
Test add(Test &t1, Test &t2)
{
	Test t3(t1.getA()+t2.getA(), t1.getB() + t2.getB()) ;//����һ��Test���󣬲����ء�
	return t3;//���ص���t3���󣬸�ֵ����������
}

//�ѳ�Ա����ת��ȫ�ֺ�������Ҫ��һ��������������
void printAB(Test *pthis)
{
	cout<<"a:"<<pthis->getA()<<"b:"<<pthis->getB()<<endl;
}
void main()
{
	Test t1(1, 2); //Test(&t1, 1, 2);
	Test t2(3, 4);
	Test t3 = add(t1, t2);

	t1.add(t2); //---->add(&t1, t2);
	t1.printAB();

	system("pause");
}