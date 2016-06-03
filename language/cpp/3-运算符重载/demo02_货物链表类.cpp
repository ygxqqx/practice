#include "iostream"
using namespace std;

//类的开发和设计,出现了两个模型
//1 贫血模型
//2 充血模型

//货物类
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

//业务操作函数 通过全局函数实现
void purchase( Goods * &f, Goods *& r, int w ) {

	Goods *p = new Goods(w); //用new 在堆中创建。
	p -> next = NULL;
	if ( f == NULL ) {

		f = r = p;
	} else {

		r->next = p;
		r = r->next; 
	}
}

//业务操作函数
void sale( Goods * & f , Goods * & r ) {

	if ( f == NULL ) { 

		cout << "No any goods!\n" ;  
		return ; 
	}
	Goods *q = f ;  
	f = f->next ;  
	delete q ;//从堆上删除。
	cout << "saled.\n" ;
}

void main() {

	Goods * front = NULL /*头*/, * rear = NULL ;
	int  w ;  
	int  choice ;
	do { 
		cout << "Please choice:\n" ;
		cout << "Key in 1 is purchase,\nKey in 2 is sale,\nKey in 0 is over.\n" ;
		cin >> choice ;
		switch ( choice ) { 
			case 1 :                                               // 键入1，购进1箱货物
				{  
					cout << "Input weight: ";
					cin >> w;
					purchase( front, rear, w ); // 从表尾插入1个结点
					break;
				}
			case 2 : 		            // 键入2，售出1箱货物
				{
					sale( front, rear );    
					break; 
				}       // 从表头删除1个结点
			case 0 :  break ; 		            // 键入0，结束
		}
		cout << "Now total weight is:" << Goods::TotalWeight() << endl ; 
	} while ( choice ) ;
} 



