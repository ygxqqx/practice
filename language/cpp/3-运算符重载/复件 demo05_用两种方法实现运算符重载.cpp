#include "iostream"
using namespace std;

//a + bi //����
class Complex
{
public:
	friend Complex operator+(Complex &c1, Complex &c2);
	friend Complex operator*(Complex &c1, Complex &c2);
	friend Complex& operator++(Complex &c1); //ǰ��++
	Complex(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	void printCom()
	{
		cout<<a<<" + "<<b<<"i "<<endl;
	}
	//ͨ�����Ա�������-����������
	Complex operator-(Complex &c2)
	{
		Complex tmp(a - c2.a, this->b - c2.b);
		return tmp;
	}
	//ͨ����Ա�������ǰ��--
	Complex& operator--()
	{
		this->a--;
		this->b--;
		return *this;
	}

private:
	int a;
	int b;
};

Complex operator+(Complex &c1, Complex &c2)
{
	Complex tmp(c1.a + c2.a, c1.b + c2.b);
	return tmp;
}

Complex operator*(Complex &c1, Complex &c2)
{
	Complex tmp(c1.a*c2.a, c1.b*c2.b);
	return tmp;
}

//ǰ��++ 
Complex& operator++(Complex &c1)
{
	c1.a ++;
	c1.b ++;
	return c1;
}

void main()
{

	Complex c1(1, 2), c2(3, 4);

	//ȫ�ֺ�������ȥʵ�ֲ���������
	//1 ���ϲ�����������һ������
	//2 ���ݲ�������1�������� 2������������ɺ����Ĳ���
	//3 ���ݺ���ԭ�ͣ�ʵ��Ҳ��Ҫҵ��
	//Complex c31 = operator+(c1, c2);
	Complex c3 = c1 + c2;

	//�����Ա����ʵ��-���������
	Complex c4 = c1 - c2;
	c4.printCom();
	//c1.operator-(c2);

	{
		//����1 ��������
		int a = 10, b = 1;
		int c = a + b;
	}

	//ǰ��++ ȫ�ֺ���
	++c1; 
	c1.printCom();

	//ǰ��-- ��Ա����
	--c1;
	c1.printCom();
	//c1.operator--()



	system("pause");
}


