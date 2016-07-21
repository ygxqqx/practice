#include "iostream"
using namespace std;

template<class T>
class Complex {
public:
	Complex(T  Real = 0,T Image=0 );
protected:
private:
	T  Real,Image  ;
};

template<class T>
Complex<T>::Complex(T  Real = 0, T Image=0 ) {
	this->Real = Real;
	this->Image = Image;
}


void main() {
	
	system("pause");
}