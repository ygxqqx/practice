#include "iostream"
using namespace std;


class Location  { 
public:
	Location( int xx = 0 , int yy = 0 ) {

		X = xx ;  Y = yy ;  
		cout << "Constructor Object.\n" ; 
	}
	Location( const Location & p ) {
		//复制构造函数 
		X = p.X ;  Y = p.Y;   
		cout << "Copy_constructor called." << endl ;  
	}
	~Location() {

		cout << X << "," << Y << " Object destroyed." << endl ; 
	}
	int  GetX () {
		
		return X;
	}		
	int GetY() {

		return Y;
	}
private :

	int  X, Y;
} ;
//alt + f8 排版
void f( Location  p ) {

	cout << "Funtion:" << p.GetX() << "," << p.GetY() << endl ; 
}

void mainobjplay() {

	Location A( 1, 2 ) ; 
	f( A ) ;
} 

void main() {

	mainobjplay();
	system("pause");
} 

