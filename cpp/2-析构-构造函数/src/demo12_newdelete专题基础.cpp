#include "iostream"
using namespace std;

//1 new delete �������� c++�Ĺؼ���
//malloc free����

//2 new �ڶ��Ϸ����ڴ�  delete 
//����������� �������������͡��������

//3

void main121()
{
	//new��������
	int *p = (int *)malloc(sizeof(int)); 
	free(p);

	int *p2 = new int; //�൱�������

	*p2 = 101;
	printf("*p2:%d \n", *p2);
	delete p2;

	//�����ڴ��ͬʱ����ʼ��
	int *p3 = new int(100);
	delete p3;
	system("pause");
}

void main122()
{
	//new����
	int *p = (int *)malloc(10*sizeof(int));  //int a[10];
	p[0] = 1;
	free(p);

	//
	int *p2 = new int[10] ;//int a[10];
	p2[0] = 1;
	p2[1] = 2;

	delete [] p2;

	system("pause");
}

class Test
{
public:
	Test(int mya, int myb)
	{
		a = mya;
		b = myb;
		cout<<"���캯�����ұ�������"<<endl;
	}
	~Test()
	{
		cout<<"�����������ұ�������"<<endl;
	}
	int getA()
	{
		return a;
	}
protected:
private:
	int a;
	int b;
};

int getTestObj(Test **my)
{
		Test *p = new Test(1, 2);
		*my = p;
		return 0;
}

void main()
{
	Test t1(1, 2);//����ʱ�������ڴ�
	//new + ����  ����һ�� �ڴ��׵�ַ
	//new������Ҳ���Զ��ĵ��������Ĺ��캯�� ��
	//delete�Զ��ĵ����������������� 
	//�൱�����ǳ���Ա�����ֹ�������Ķ������������
	Test *p = new Test(1, 2);
	cout<<p->getA()<<endl;
	delete p;


	getTestObj(&p);
	delete p;



	system("pause");
}