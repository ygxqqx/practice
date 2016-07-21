#include "iostream"
using namespace std;

//��Ŀ��������,����������ģ��
//1 ƶѪģ��
//2 ��Ѫģ��

//������
class Goods { 
public :
	Goods( int  w) {

		weight = w ;  total_weight += w;
	}
	~ Goods() {
		total_weight -= weight;
	}
	int  Weight() {

		return  weight; 
	}	
	static int TotalWeight() {

		return total_weight;
	}  
	Goods *next;
private :
	int weight;
	static int total_weight;
} ;

int Goods::total_weight = 0;

//ҵ��������� ͨ��ȫ�ֺ���ʵ��
void purchase( Goods * &f, Goods *& r, int w ) {

	Goods *p = new Goods(w); //��new �ڶ��д�����
	p -> next = NULL;
	if ( f == NULL ) {

		f = r = p;
	} else {

		r->next = p;
		r = r->next; 
	}
}

//ҵ���������
void sale( Goods * & f , Goods * & r ) {

	if ( f == NULL ) { 

		cout << "No any goods!\n" ;  
		return ; 
	}
	Goods *q = f ;  
	f = f->next ;  
	delete q ;//�Ӷ���ɾ����
	cout << "saled.\n" ;
}

void main() {

	Goods * front = NULL /*ͷ*/, * rear = NULL ;
	int  w ;  
	int  choice ;
	do { 
		cout << "Please choice:\n" ;
		cout << "Key in 1 is purchase,\nKey in 2 is sale,\nKey in 0 is over.\n" ;
		cin >> choice ;
		switch ( choice ) { 
			case 1 :                                               // ����1������1�����
				{  
					cout << "Input weight: ";
					cin >> w;
					purchase( front, rear, w ); // �ӱ�β����1�����
					break;
				}
			case 2 : 		            // ����2���۳�1�����
				{
					sale( front, rear );    
					break; 
				}       // �ӱ�ͷɾ��1�����
			case 0 :  break ; 		            // ����0������
		}
		cout << "Now total weight is:" << Goods::TotalWeight() << endl ; 
	} while ( choice ) ;
} 



