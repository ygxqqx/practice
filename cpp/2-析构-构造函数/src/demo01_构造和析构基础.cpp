#include "iostream"
using namespace std;

class Test
{
public:
	Test()
	{
		p = (char *)malloc(100);
		strcpy(p, "11111");
		cout<<"���ǹ��캯�����Զ���������"<<endl;
	}

	~Test()
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
	char *p ;
};

//�����һ����̨
void ObjPlay()
{
		Test t1, t2;
		cout<<"չʾt1����������"<<endl;
}

void main()
{
	ObjPlay();
	system("pause");
}