#include "iostream"
#include "Array.h"
using namespace std;


Array::Array(int length) {

    if ( length < 0 ) {

        length = 0;
    }
    
    mLength = length;
    mSpace = new int[mLength];
}

Array::Array(const Array& obj) {

    mLength = obj.mLength;
    
    mSpace = new int[mLength];
    
    for (int i=0; i<mLength; i++) {

        mSpace[i] = obj.mSpace[i];
    }
}

int Array::length() {

    return mLength;
}

void Array::setData(int index, int value) {

    mSpace[index] = value;
}

int Array::getData(int index) {

    return mSpace[index];
}

Array::~Array() {

    mLength = -1;
    delete[] mSpace;
}

//һ������������غ���
//������������Ԫ��
/*
int Array::operator[](int i) 3k
{
	return mSpace[i];
}
*/

//һ������������غ��� 
//������������Ԫ��
int& Array::operator[](int i) {

	return mSpace[i];
}

/*
//����2
Array a3(20);
a3 = a1;
*/
Array& Array::operator=(Array &a1) {

	int i = 0;

	if (this->mSpace != NULL) {

		delete[] mSpace;
		this->mLength = 0;
	}
	//a1������Ԫ�ظ���a3
	this->mLength = a1.mLength;
	this->mSpace = new int[a1.mLength];

	for (i=0; i<this->mLength; i++) {

		mSpace[i] = a1[i];
	}

	return *this;
}

//����3
//if (a1 == a2)  //����3

bool Array::operator==(Array &a2) {

	if (this->mLength != a2.mLength) {

		return false;
	}
	for (int i=0; i<this->mLength; i++) {

		if (this->mSpace[i] != a2[i]) {

			return false;
		}
	}
	return true;
}

//	if (a1 != a2) //����4
bool Array::operator!=(Array &a2) {

	return !(*this == a2);
}

