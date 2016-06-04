
#include<iostream>
using namespace std;

template<class T>
class Complex { 
public:
	Complex( T r =0, T i =0 );
	Complex(T a) { Real = a ;  Image = 0 ; } 
	void print() const;
	friend Complex<T> operator+ ( const Complex<T> & c1, const Complex<T> & c2 ) {
		T r = c1.Real + c2.Real ;     
		T i = c1.Image+c2.Image ;
		return Complex<T>( r, i ) ;
	}
	friend Complex<T> operator- ( const Complex<T> & c1, const Complex<T> & c2 ) {
		T r = c1.Real - c2.Real ;    T i = c1.Image - c2.Image ;
		return Complex<T>( r, i ) ;
	}
	friend Complex<T> operator- ( const Complex<T> & c ) {
		return Complex<T>( -c.Real, -c.Image );
	}
private:  
	T  Real, Image;
};

template<class T> 
Complex<T>::Complex( T r, T i ) {
	Real = r;
	Image = i;
}


template<class T> 
void Complex<T>::print()const { 
	cout << '(' << Real << " , " << Image << ')' << endl; 
}

/*
template<class T> //注意这里有非法不可见字符
Complex<T> operator+ (const Complex<T>& c1, const Complex<T> & c2 )
{ 
	T r = c1.Real + c2.Real ;     
	T i = c1.Image+c2.Image ;
	return Complex<T>( r, i ) ;
}*/

/*
template<typename T> Complex<T> operator- ( const Complex<T> & c1, const Complex<T> & c2 )
{
	//T r = c1.Real - c2.Real ;    T i = c1.Image - c2.Image ;
	//return Complex<T>( r, i ) ;
}
*/


/*
template<typename T>
Complex<T> operator- ( const Complex<T> & c )
{ 
	return Complex<T>( -c.Real, -c.Image );
}
*/


void main99() {
	Complex<double>  c1( 2.5, 3.7 ), c2( 4.2, 6.5 ) ;
	Complex<double> c;
	c = c1+ c2;    
	c.print();
	c = c2 + c2;
	c.print();
	c = - c1;
	c.print() ;
	system("pause");
}
