#include "iostream"
using namespace std;

class Test
{
public:
	//�����д��copy���캯������ô�������������ṩ�޲ι��캯��
	Test(Test &obj)
	{
		cout<<"����copy���캯��"<<endl;
		//a = 1;
		//b = 2;
	}
	//�����д���вλ����޲ι��캯������ô������Ҳ�����ṩ�޲ι��캯��
	Test(int _a, int _b)
	{
		cout<<"����copy���캯��"<<endl;
		//a = 1;
		//b = 2;
	}
protected:
private:
	int a ;
	int b;
};

void main()
{
	Test t1;
	//Test t2;
	//Test t3 = t2;
	system("pause");
}