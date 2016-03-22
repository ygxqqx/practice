

#include "iostream"
#include "Array.h"
using namespace std;


Array::Array(int length)
{
    if( length < 0 )
    {
        length = 0;
    }
    
    mLength = length;
    mSpace = new int[mLength];
}

Array::Array(const Array& obj)
{
    mLength = obj.mLength;
    
    mSpace = new int[mLength];
    
    for(int i=0; i<mLength; i++)
    {
        mSpace[i] = obj.mSpace[i];
    }
}

int Array::length()
{
    return mLength;
}

void Array::setData(int index, int value)
{
    mSpace[index] = value;
}

int Array::getData(int index)
{
    return mSpace[index];
}

Array::~Array()
{
    mLength = -1;
    delete[] mSpace;
}

