#include "iostream"
using namespace std;

class B {	
public:
	int i;
protected:
private:
};

class B1 : virtual public B {	
public:
	int b1;
protected:
private:
};

class B2 :virtual  public B {	
public:
	int b2;
protected:
private:
};

class C :public B1, public B2 {
public:
protected:
private:
};
void main() {

	C c1;
	c1.b1 = 10;
	c1.b2 = 20;
	c1.i = 100;

	system("pause");
}