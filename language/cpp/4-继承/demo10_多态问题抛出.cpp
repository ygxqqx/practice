#include "iostream"
using namespace std;

//����һ�������һ������
class Parent {

public:
	Parent(int a = 0) {

		this->a = a;
	}
	virtual void print() {

		cout<<"����a:"<<a<<endl;
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
	void print() {

		cout<<"����b:"<<b<<endl;
	}
protected:
private:
	int  b;
};


//�������������
//����Ҵ�һ���������ִ�и����print����
//����Ҵ�һ���������ִ�������printf����


//���������ԭ��
//��ֵ������ԭ�����Ϻ�����д ���ֵ�һ������
//1 û�����ɱ���
//2 �Ա����ú���������
//3 �ڱ����������ڼ䣬�Ҿ�ȷ���ˣ���������Ĳ�����p����Parent���͵ġ�����
//��̬����
void HowToPrint1(Parent *p) {

	p->print(); //һ�仰���ж���Ч�����ж��ֱ�����̬�ѡ�����//������ܵľ��Ƕ�̬
}
void HowToPrint2(Parent &myp) {

	myp.print();
}
void main() {

	Parent p1;
	Child c1;
	/*
	p1.print();
	c1.print();

	
	Parent *p = NULL;
	p = &p1;
	p->print(); //���ø���Ĵ�ӡ����

	////��ֵ������ԭ�� ���� ͬ��������ʱ�� 
	p = &c1; 
	p->print(); //

	Parent &myp = c1;
	myp.print(); 
	*/


	HowToPrint1(&p1);
	HowToPrint1(&c1);

	HowToPrint2(p1);
	HowToPrint2(c1);

	system("pause");
}