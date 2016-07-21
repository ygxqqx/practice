#include "iostream"
using namespace std;


class Name {
public:
	Name(const char *pname) {

		size = strlen(pname);
		pName = (char *)malloc(size + 1);
		strcpy(pName, pname);
	}
	Name(Name &obj) {

		//用obj来初始化自己
		pName = (char *)malloc(obj.size + 1);
		strcpy(pName, obj.pName);
		size = obj.size;
	}
	~Name() {

		cout<<"开始析构"<<endl;
		if (pName!=NULL) {

			free(pName);
			pName = NULL;
			size = 0;
		}
	}

protected:
private:
	char *pName;
	int size;
};

void playObj() {

	Name obj1("obj1.....");
	Name obj2 = obj1;
	cout<<"业务操作......5000"<<endl;
}

void main() {

	playObj();
	system("pause");
}
