#include "iostream"
using namespace std;
//����
//ʵ�ַ���3
//��̬��ԭ�� 
//

class Parent {
public:
	//�ڸ���Ĺ��캯�����棬�����麯�������������̬����
	//����֮�⣺�������������麯����������
	Parent(int a = 0) {
		//print(); //
		this->a = a;
	}
	virtual ~Parent() {
		cout<<"���ø�������������"<<endl;
	}

	void printAbc() {
		printf("����abc");
	}
	//��һ�����ֽŵĵط� ������Ӧ�ö�����麯�����⴦��������
	virtual void print() {
		cout<<"���ຯ��"<<endl;
	}
protected:
private:
	int a;
};

class Child : public Parent {
public:
	Child(int b = 0) {
		this->b = b;
	}
	~Child() {
		cout<<"�������������������"<<endl;
	}
	virtual void print() {
		cout<<"���ຯ��"<<endl;
	}
protected:
private:
	int b ;
};

//�ڸ���������������������ԭ��
//ͨ������ָ�룬�����е���������������ִ��һ�顣����
//
void howtoDel(Parent *pbase) {
	delete pbase;
}

void mainobj() {
	Parent *p1 = new Parent();
	p1->print();
	delete p1;
}

void main() {
	Child *pc1 = new Child();

	howtoDel(pc1);
	//mainobj();
	system("pause");
}