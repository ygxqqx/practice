#include "iostream"
using namespace std;


class Name
{
public:
	Name(const char *pname)
	{
		size = strlen(pname);
		pName = (char *)malloc(size + 1);
		strcpy(pName, pname);
	}
	Name(Name &obj)
	{
		//��obj����ʼ���Լ�
		pName = (char *)malloc(obj.size + 1);
		strcpy(pName, obj.pName);
		size = obj.size;
	}
	~Name()
	{
		cout<<"��ʼ����"<<endl;
		if (pName!=NULL)
		{
			free(pName);
			pName = NULL;
			size = 0;
		}
	}
	void operator=(Name &obj3)
	{
		if (pName != NULL)
		{
			free(pName);
			pName = NULL;
			size = 0;
		}
		cout<<"������û�е����ҡ�������"<<endl;

		//��obj3��=�Լ�
		pName = (char *)malloc(obj3.size + 1);
		strcpy(pName, obj3.pName);
		size = obj3.size;

	}

protected:
private:
	char *pName;
	int size;
};

//����ĳ�ʼ�� �� ����֮��=�Ų�����������ͬ�ĸ���
void playObj()
{
	Name obj1("obj1.....");
	Name obj2 = obj1; //obj2��������ʼ��

	Name obj3("obj3...");

	//����=�Ų�����
	obj2 = obj3; //=�Ų���


	cout<<"ҵ�����������5000"<<endl;

}
void main()
{
	playObj();
	system("pause");
}