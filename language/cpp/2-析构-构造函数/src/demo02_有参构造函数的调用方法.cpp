#include "iostream"
using namespace std;

class Test02
{
public:
	Test02() //�޲ι��캯�� Ĭ�Ϲ��캯��
	{
		p = (char *)malloc(100);
		strcpy(p, "11111");
		cout<<"���ǹ��캯�����Զ���������"<<endl;
	}

	Test02(int _a=0, int _b=0) //�޲ι��캯�� Ĭ�Ϲ��캯��
	{
		p = (char *)malloc(100);
		strcpy(p, "11111");
		a = _a;
		b = _b;
		cout<<"���ǹ��캯�����Զ���������"<<endl;
	}


	~Test02()
	{
		cout<<"���������������Զ���������"<<endl;
		if (p != NULL)
		{
			free(p);
		}

	}
protected:
private:
	int a;
	int b;
	char *p ;
};

//�����һ����̨
void ObjPlay()
{
	Test02 t1(1, 2);

	Test02 t2 = (1, 2);

	Test02 t3 = Test02(3, 4);
	cout<<"չʾt1����������"<<endl;
}

void main()
{
	ObjPlay();
	system("pause");
}