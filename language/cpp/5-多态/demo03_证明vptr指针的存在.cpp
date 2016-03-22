#include "iostream"
using namespace std;

class AA
{
public:
	virtual void print()
	{
		printf("dddd\n");
	}
protected:
private:
	int b;
};

void main()
{
	printf("AA%d \n", sizeof(AA));
	AA  a; //

	system("pause");
}