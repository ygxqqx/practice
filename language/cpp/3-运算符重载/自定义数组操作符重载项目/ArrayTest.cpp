#include "iostream"
#include "Array.h"
using namespace std;

int main()
{
    Array a1(10);
    
    for(int i=0; i<a1.length(); i++)
    {
        //a1.setData(i, i); 
		a1[i] = i;
		//a1.operator [](i) = i;
		//10 = i;
    }
    
    for(int i=0; i<a1.length(); i++)
    {
        //printf("array %d: %d\n", i, a1.getData(i));
		printf("array %d: %d\n", i, a1[i]);  //����1
    }
    
    Array a2 = a1;
    
    for(int i=0; i<a2.length(); i++)
    {
        printf("array %d: %d\n", i, a2.getData(i));
		//printf("array %d: %d\n", i, a2[i]);
    }

	
	//����2
	Array a3(20);
	a2 = a3 = a1;  
	//a2 = void
	//a3.operator=(a1);
	
	
	//a1.operator==(a2);
	if (a1 == a2)  //����3
	{
		printf("���\n");
	}
	else
	{
		printf("�����\n");
	}

	
	if (a1 != a2) //����4
	{
		printf("�����\n");
	}
	else
	{
		printf("���\n");
	}
	
    
    system("pause");
    return 0;
}
