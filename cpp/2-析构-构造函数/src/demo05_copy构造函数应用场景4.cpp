
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

//40 =�ȺŲ��� 
//42 �����ʼ������  
//�����ʼ������ �� =�ȺŲ��� ��������ͬ�ĸ���
void mainobjplay()
{  
	//Location B;
	//B = g();

	Location B = g();
	//������ص�������������ʼ������һ��ͬ���͵��������ô���������ֱ��ת���µĶ��󡣡���
	//���������ȥ�������ؼ���������ʱ��νӹ�����
	cout<<"���Բ���"<<endl;
} 

void main()
{  
	mainobjplay();
	system("pause");
} 

