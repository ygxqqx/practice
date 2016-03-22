#include "iostream"
using namespace std;

//a + bi //����
class Complex
{
public:
	friend ostream& operator<<(ostream &out, Complex &c1);
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
	Complex operator+(Complex &c2)
	{
		Complex tmp(a + c2.a, this->b + c2.b);
		return tmp;
	}
	//ͨ����Ա�������ǰ��--
	Complex& operator--()
	{
		this->a--;
		this->b--;
		return *this;
	}
	//ͨ����Ա�������ǰ��--
	Complex& operator++()
	{
		this->a++;
		this->b++;
		return *this;
	}

	//ͨ�����Ա������ɺ���--
	Complex operator--(int)
	{
		Complex tmp = *this;
		this->a--;
		this->b--;
		return tmp;
	}
	//ͨ�����Ա������ɺ���--
	Complex operator++(int)
	{
		Complex tmp = *this;
		this->a++;
		this->b++;
		return tmp;
	}

private:
	int a;
	int b;
};

void main61()
{

	Complex c1(1, 2), c2(3, 4);

	//ȫ�ֺ�������ȥʵ�ֲ���������
	//1 ���ϲ�����������һ������
	//2 ���ݲ�������1�������� 2������������ɺ����Ĳ���
	//3 ���ݺ���ԭ�ͣ�ʵ����Ҫҵ��
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

	//����++ ȫ�ֺ���
	c1++; //operator++(c1);
	c1.printCom();

	//����-- ���Ա����
	c1--;  //c1.operator--()
	c1.printCom();

	system("pause");
}

ostream& operator<<(ostream &out, Complex &c1)
{
	//out<<"12345���������ǿ�"<<endl;
	out<<c1.a<<" + "<<c1.b<<"i "<<endl;
	return out;
}
void main()
{
	Complex c1(1, 2), c2(3, 4);
	int a = 10;
	char *p = "addddd";
	cout<<"a"<<a<<endl;
	cout<<"p"<<p<<endl;

	//Complex�Զ������� ��a + bi ab ba
	cout<<c1;

	//ȫ�ֺ��� 
	//cout<<c1;
	//operator<<(cout, c1);

	//1
	//���Ա����
	//��Ϊ��û�з����õ�cout������Դ�롣������AOP C++
	//cout.operator<<(c1);

	//2 ֧����ʽ���
	cout<<c1<<"abcc";

	//��������ֵ����ֵ��Ҫ�󷵻�һ�����á���������
	
	//cout.operator<<(c1).operator<<("abcd");

	//s<<"abcd"

	//s cout.operator<<(c1);

	//s.operator<<("abcd");



	system("pause");

}



