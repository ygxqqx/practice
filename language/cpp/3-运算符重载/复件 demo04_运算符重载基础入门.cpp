#include "iostream"
using namespace std;

//a + bi //����
class Complex
{
public:
	friend Complex operator+(Complex &c1, Complex &c2);
	Complex(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	void printCom()
	{
		cout<<a<<" + "<<b<<"i "<<endl;
	}

private:
	int a;
	int b;
};

/*
//ͨ��ȫ�ֺ�����ɶ����
Complex add(Complex &c1, Complex &c2)
{
	Complex c3(c1.a + c2.a, c1.b+c2.b);
	return c3;
}
*/
Complex operator+(Complex &c1, Complex &c2)
{
	Complex c3(c1.a + c2.a, c1.b+c2.b);
	return c3;
}
void main()
{
	{
		int a = 0, b = 0;
		int c = a + b;
		//���ڻ������ͣ������Ѿ�֪����ν��мӼ�
	}
	Complex c1(1, 2), c2(3, 4);
	//ΪʲôҪ�����������
	//ԭ�� Complex���û��Զ������͡���������������֪����ν��мӼ�������
	//�����������ṩ��һ�ֻ��ƣ����û��Լ�ȥ��ɣ��Զ������͵ļӼ���������������
	//������ƾ�����������ػ���

	//Complex c3 = c1 + c2;

	//Complex c3 = add(c1, c2);
	//Complex c3 = operator+(c1, c2);


	Complex c3 = c1 + c2;
	c3.printCom();


	system("pause");
}