#include "iostream"
using namespace std;

//��ģ��Ĵ���
//���е����ԣ������Ͳ�����

//���ǰ��������ͣ���һ�� ���󻯡�����
//���󻯵��������ͣ�����ֱ��ʹ�á���
template<typename T>
class A {
public:
	
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

void printA(A<int> *p) {
	 cout<<"��ӡa��"<<p->getA()<<endl;
}

void printA2(A<char> *p) {
	cout<<"��ӡa��"<<p->getA()<<endl;
}

void main() {
	
	A<char> a1;
	A<int> b1;
	b1.setA(10);
	cout<<"��ӡa��"<<b1.getA()<<endl;
	printA(&b1);
	system("pause");
}