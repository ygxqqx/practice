#include "iostream"
using namespace std;

//C 
class Test {
public:
protected:
private:
	int a;
	const int A() { //const // ====>int A(const this)
		//�۵�1:const������a,����ͨ������,���Ƿ���,b++Ҳ���ܱ���ͨ��
		//��˵��:const��a �� b��������.......

		//����:��Ϊthis��Ϊ�����ĵ�һ������,������......constû�еط���......
		//
		//const������this

		a++;
		//b++;
		return a; 
	}
	void A(int val) {

		a = val; 
	}

	int BBB() {
		
		return a;
	}

	int b;
};


int Aaaaa(const Test *pthis) {

	return 10; 
}
void main() {

	Test t1;
	system("pause");
}
