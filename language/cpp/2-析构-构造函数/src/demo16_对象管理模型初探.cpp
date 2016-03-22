#include "iostream"
using namespace std;

class Test
{
public:
	Test(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	void getA() //getA(this);
	{
		printf("a:%d \n", this->a);
		printf("a:%d \n", a);
	}

protected:
private:
	int a;
	int b;
};
void main()
{
	Test t(1,2); //====>Test(this, 1, 2);===>Test(&t, 1, 2);
	system("pause");
}