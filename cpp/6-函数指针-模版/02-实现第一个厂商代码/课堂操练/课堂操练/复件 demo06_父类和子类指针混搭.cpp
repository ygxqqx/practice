#include "iostream"
using namespace std;



class Parent01
{
protected:
	int i;
	int		j;
public:
	virtual void f()
	{
		cout<<"Parent01::f"<<endl;
	}
};

//һ��żȻ�ĳɹ����ȱ�Ȼ��ʧ�ܸ�����
class Child01 : public Parent01
{	
public:
	//int k;
public:
	Child01(int i, int j)
	{
		printf("Child01:...do\n");
	}

	virtual void f()
	{
		printf("Child01::f()...do\n");
	}
};

void howToF(Parent01 *pBase)
{
	pBase->f();
	
}


int main()
{
	int i = 0;
	Parent01* p = NULL;
	Child01* c = NULL;


	//����ʹ�ø�ֵ������ԭ�������ڶ�̬�ĵط�
	//��Ҫ����ͨ������ָ��p++,��ִ�к�������
	//����ı��� ����ָ�� �͸���ָ�� �������ܲ�һ��������
	Child01 ca[3] = {Child01(1, 2), Child01(3, 4), Child01(5, 6)};


	p = ca; //��һ���������ֵ��p��p�ǻ���ָ�룬
	c = ca;

	p->f(); //�ж�̬����
	//c->f(); //

	p++;
	//c++;
	
	p->f();//�ж�̬����
 	//c->f();

// 	for (i=0; i<3; i++)
// 	{
// 		howToF(&(ca[i]));
// 	}


	system("pause");
	return 0;
}

