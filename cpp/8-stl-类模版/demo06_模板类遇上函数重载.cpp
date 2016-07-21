#include "iostream"
using namespace std;

template<class T>
class Complex {
public:
	Complex(T  Real = 0,T Image=0 );
	Complex(T a);
	//Complex Complex<T>::operator+(Complex &c1, Complex &c2 )
	friend  Complex operator+(Complex &c1, Complex &c2 );

	friend Complex operator-(Complex &c1, Complex &c2 ) {
		Complex tmp(c1.Real-c2.Real, c1.Image - c2.Image);
		return tmp;
	}
	
	void print();

public:
	
protected:
private:
	T  Real,Image  ;
};

template<class T>
Complex<T>::Complex(T  Real = 0, T Image=0 ) {
	this->Real = Real;
	this->Image = Image;
}

template<class T>
Complex<T>::Complex(T a) {
	this->Real = a; this->Image = 0;
}

template<class T>
void Complex<T>::print() {
	cout<<this->Real<<" + "<<this->Image<<endl;
};

/*
�޷��������ⲿ���� "
class Complex<float> __cdecl operator+(class Complex<float> &,class Complex<float> &)
	" (??H@YA?AV?$Complex@M@@AAV0@0@Z)���÷����ں��� _main �б�����
	1>E:\01-work\10-��ҵ��0529\day16\����ģ����ò���\Debug\����ģ����ò���.exe :
fatal error LNK1120: 1 ���޷��������ⲿ����
	========== ����: �ɹ� 0 ����ʧ�� 1 �������� 0 �������� 0 �� ==========
*/
/*
template<class T>
Complex<T> operator+(Complex<T> &c1, Complex<T> &c2 )
{
	Complex<T> tmp(c1.Real+c2.Real, c1.Image + c2.Image);
	return tmp;
}
*/

void main() {
	
	Complex<float> c1(1.0, 2.0);
	Complex<float> c2(3.0, 4.0);
	c1.print();
	//Complex<float> c3 = c1 + c2;
	//c3.print();
	Complex<float> c4 = c1 - c2;
	c4.print();
	system("pause");
}