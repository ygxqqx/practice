#include "iostream"
#include <stdio.h>
using namespace std;


template<typename T>
void myswap(T &a, T &b) {
	T c ;
	c = a;
	a = b;
	b = c;
}

void myswap(int &a,char &b) {
	printf("dddd\n");
}
int main() {
	int a = 10;
	char b = 'b';
	myswap(a, b);
	return 0;
}