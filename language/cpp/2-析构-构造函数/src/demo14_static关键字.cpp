#include "iostream"
using namespace std;


class BB
{
public:
	int getC()
	{
		return c;
	}
	void setC(int nyc)
	{
		c = nyc;
		
	}
	 //��̬��Ա���������������࣬
	//����ľ�̬���ݳ�Ա�����У��ǲ��ܵ��þ���Ķ���ı��������ԡ�����������ש��
	//���ܵ�����ͨ��Ա����
	static void getMem()
	{
		//cout<<a<<endl;
		cout<<c<<endl;
	}
protected:
private:
	int a;
	int b;
	static int c;
};
 int BB::c = 0;

 //static���εı������������࣬�����еĶ����ܹ����á�
void main111()
{
	BB b1;
	BB b2;
	cout<<b2.getC()<<endl;;
	b1.setC(100);
	cout<<b2.getC()<<endl;;

	system("pause");
}

void main()
{
	//���þ�̬��Ա�����ķ���1
	BB::getMem();

	//���þ�̬��Ա�����ķ���2
	BB b1;
	b1.getMem();

	system("pause");
}