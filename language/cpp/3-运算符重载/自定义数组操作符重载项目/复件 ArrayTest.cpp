#include "iostream"
#include "Array.h"
using namespace std;

int main() {

    Array a1(10);
    
    for (int i=0; i<a1.length(); i++) {
    	
        a1.setData(i, i); 
		//a1[i] = i;
    }
    
    for (int i=0; i<a1.length(); i++) {
    	
        printf("array %d: %d\n", i, a1.getData(i));
		//printf("array %d: %d\n", i, a1[i]);  ����1
    }
    
    Array a2 = a1;
    
    for (int i=0; i<a2.length(); i++) {
    	
        printf("array %d: %d\n", i, a2.getData(i));
		//printf("array %d: %d\n", i, a2[i]);
    }

	/*
	Array a3(20);
	a3 = a1;  //����2
	*/

	/*
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
	*/
    
    system("pause");
    return 0;
}
