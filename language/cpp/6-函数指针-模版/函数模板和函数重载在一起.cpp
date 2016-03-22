#include "iostream"
using namespace std;


template<typename T>
void myswap(T &a, T &b)
{
	T c ;
	c = a;
	a = b;
	b = c;

}

void myswap(int &a,char &b)
{
	printf("dddd\n");
}
void main()
{
	int a = 10;
	char b = 'b';
	myswap(a, b);
	system("pause");
}