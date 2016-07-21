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

		//��obj����ʼ���Լ�
		pName = (char *)malloc(obj.size + 1);
		strcpy(pName, obj.pName);
		size = obj.size;
	}
	~Name() {

		cout<<"��ʼ����"<<endl;
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
	cout<<"ҵ�����......5000"<<endl;
}

void main() {

	playObj();
	system("pause");
}
