#include "iostream"
using namespace std;

//��ģ��Ĵ���
//���е����ԣ������Ͳ�����
//���ǰ��������ͣ���һ�� ���󻯡�����
//���󻯵��������ͣ�����ֱ��ʹ�á���
template<typename T>
class A {
public:

	//ע�⺯�����������ͺ���ʵ�ֵ�����
	//��������
	A(int a) {
		this->a = a;
	}

	~A() {

	}
	T getA() {
		return a;
	}
	void setA(T a) {
	 this->a = a;
	}
protected:
private:
	 T a;
};

/*

void printA(A<int> *p)
{
	cout<<"��ӡa��"<<p->getA()<<endl;
}

void printA2(A<char> *p)
{
	cout<<"��ӡa��"<<p->getA()<<endl;
}
void main51()
{

	A<char> a1;
	A<int> b1(19);
	b1.setA(10);
	cout<<"��ӡa��"<<b1.getA()<<endl;
	//printA(&b1);

	system("pause");
}
*/



class B {
public:
protected:
private:
	int b;
};

//a��һ�����󻯵����ͣ������������ͣ�������������ֱ��ʹ��
class C : public A<int> {
public:
	C(int c, int a) : A<int>(a) {
		this->c = c;
	}
protected:
private:
	int c;
};

void printC(C *myc) {
	cout<<myc->getA()<<endl;
}
void main() {

	C  myc(1, 2);
	printC(&myc);
	system("pause");
}
