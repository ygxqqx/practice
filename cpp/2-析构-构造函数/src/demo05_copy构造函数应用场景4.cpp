
#include "iostream"
using namespace std;


class Location 
{ 
public:
	Location( int xx = 0 , int yy = 0 ) 
	{ 
		X = xx ;  Y = yy ;  cout << "Constructor Object.\n" ; 
	}
	Location( const Location & p ) 	    //复制构造函数
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
//alt + f8 排版
void f ( Location  p )   
{ 
	cout << "Funtion:" << p.GetX() << "," << p.GetY() << endl ; 
}

Location g()
{
	Location A(1, 2);
	return A;
}

//40 =等号操作 
//42 对象初始化操作  
//对象初始化操作 和 =等号操作 是两个不同的概念
void mainobjplay()
{  
	//Location B;
	//B = g();

	Location B = g();
	//如果返回的匿名对象，来初始化另外一个同类型的类对象，那么匿名对象会直接转成新的对象。。。
	//匿名对象的去和留，关键看，返回时如何接过来。
	cout<<"测试测试"<<endl;
} 

void main()
{  
	mainobjplay();
	system("pause");
} 

