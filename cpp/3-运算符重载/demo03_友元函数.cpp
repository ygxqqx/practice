#include "iostream"
using namespace std;

class A1 {
public:
	A1() {

		a1 = 100;
		a2 = 200;
	}
	int getA1() {

		return this->a1;
	}
	//����һ����Ԫ����
	friend void setA1(A1 *p, int a1); //ʲô��������������ĺ�����
	
protected:
private:
	int a1;
	int a2;
};

void setA1(A1 *p, int a1) {

	p->a1 = a1;
}
//friend �ƻ�����ķ�װ�ԡ�������
//friend�ؼ�����һ����ϵ��
//why ����֮�� java class
//java---��1.class==��class==>java��
//java��ķ��� sun jdk api

//cc++ 1Ԥ����gcc -E 2��� gcc -i 3����gcc -c 3������ld ===��������
//friend 
//Ӧ�ó�������������
//const�ؼ��� ð�ƻ�c
//register
//typedef ����� 

void main11() {

	A1 mya1;
	cout<<mya1.getA1()<<endl;
	setA1(&mya1, 300);
	cout<<mya1.getA1()<<endl;

	system("pause");
}

class A {
	//b��a�ĺ�����	
	friend class B;
public:
	void display() {

		cout<<x<<endl;
	}

protected:
private:
	int x;
};

class B {
public:
	void setA(int x) {

		Aobj.x = x;
	}
	void printA() {

		cout<<Aobj.x<<endl;
	}
protected:
private:
	A Aobj;

};

void main() {
	
	B b1;
	b1.setA(100);
	b1.printA();
	system("pause");
}