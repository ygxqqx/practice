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
无法解析的外部符号 "
class Complex<float> __cdecl operator+(class Complex<float> &,class Complex<float> &)
	" (??H@YA?AV?$Complex@M@@AAV0@0@Z)，该符号在函数 _main 中被引用
	1>E:\01-work\10-就业班0529\day16\函数模板课堂操练\Debug\函数模板课堂操练.exe :
fatal error LNK1120: 1 个无法解析的外部命令
	========== 生成: 成功 0 个，失败 1 个，最新 0 个，跳过 0 个 ==========
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