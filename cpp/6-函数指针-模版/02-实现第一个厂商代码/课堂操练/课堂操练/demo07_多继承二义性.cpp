#include "iostream"
using namespace std;

class B
{
public:
	int k ;
protected:
private:
};

class B1 : virtual public B
{
public:
protected:
private:
};

//virtual倡写覚。。。。
class B2 :virtual public B
{
public:
protected:
private:
};
class C : public B1, public B2
{
public:
protected:
private:
};
void main()
{
	C c1;
	c1.k = 10;
	
	system("pause");
}