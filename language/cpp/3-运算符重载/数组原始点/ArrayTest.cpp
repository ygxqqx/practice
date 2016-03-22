#include "iostream"
#include "Array.h"
using namespace std;

int main()
{
    Array a1(10);
    
    for(int i=0; i<a1.length(); i++)
    {
        a1.setData(i, i); 
    }
    
    for(int i=0; i<a1.length(); i++)
    {
        printf("array %d: %d\n", i, a1.getData(i));
    }
    
    Array a2 = a1;
    
    for(int i=0; i<a2.length(); i++)
    {
        printf("array %d: %d\n", i, a2.getData(i));
    }
    
    system("pause");
    return 0;
}
