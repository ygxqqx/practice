#include "iostream"
using namespace std;

class Parent {
public:
	void printP() {
		printf("���ǵ�������\n");
	}
protected:
	int a;
	int b;
};

class Child : public Parent {
public:
	Child() {
		a = 0; b = 0; c= 0;
	}
	void printC() {
		printf("���Ƕ��ӡ�����\n");
	}
protected:
private:
	int c;
};


void howToPrint(Parent *p) {
	p->printP();
}

void howToPrint2(Parent &p) {
	p.printP();
}

//��ֵ������ԭ��
/*
���������Ե����������ʹ��
	����������ֱ�Ӹ�ֵ���������
	����������ֱ�ӳ�ʼ���������
	����ָ�����ֱ��ָ���������
	�������ÿ���ֱ�������������
*/

void main() {
	Parent p1;
	p1.printP();

	Child c1;
	c1.printC();


	Parent *base = NULL;
	base = &c1;
	
	//���԰�������󸳸�����ָ��
	//�������һ������ĸ���
	//
	base->printP();


	Parent &myp = c1;
	myp.printP();


	//���Ը���ָ�룬����������
	howToPrint(&p1);
	howToPrint(&c1);

	//���Ը������ã�����������
	howToPrint2(p1);
	howToPrint2(c1);

	//�����������������ʼ��������󡣡�����

	//���Ǳ������������ṩ����Ϊ������ֻ��˳��
	Parent p3 = c1;
	
	system("pause");
}