
#include "iostream"
using namespace std;


class Location 
{ 
public:
	Location( int xx = 0 , int yy = 0 ) 
	{ 
		X = xx ;  Y = yy ;  cout << "Constructor Object.\n" ; 
	}
	Location( const Location & p ) 	    //���ƹ��캯��
	{ 
		X = p.X ;  Y = p.Y ;   cout << "Copy_constructor called." << endl ;  
	}
	~Location() 
	{ 
		cout << X << "," << Y << " Object destroyed." << endl ; 
	}
	int  GetX () { return X ; }		int GetY () { return Y ; }
private :   int  X , Y ;
} ;

//alt + f8 �Ű�
void f ( Location  p )   
{ 
	cout << "Funtion:" << p.GetX() << "," << p.GetY() << endl ; 
}

Location g()
{
	Location A(1, 2);
	return A;
}

void mainobjplay()
{  
	Location B;
	B = g();

	//Location B = g();
} 

void main()
{  
	mainobjplay();
	system("pause");
} 

