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
		//用obj来初始化自己
		pName = (char *)malloc(obj.size + 1);
		strcpy(pName, obj.pName);
		size = obj.size;
	}
	~Name()
	{
		cout<<"开始析构"<<endl;
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
		cout<<"测试有没有调用我。。。。"<<endl;

		//用obj3来=自己
		pName = (char *)malloc(obj3.size + 1);
		strcpy(pName, obj3.pName);
		size = obj3.size;

	}

protected:
private:
	char *pName;
	int size;
};

//对象的初始化 和 对象之间=号操作是两个不同的概念
void playObj()
{
	Name obj1("obj1.....");
	Name obj2 = obj1; //obj2创建并初始化

	Name obj3("obj3...");

	//重载=号操作符
	obj2 = obj3; //=号操作


	cout<<"业务操作。。。5000"<<endl;

}
void main()
{
	playObj();
	system("pause");
}