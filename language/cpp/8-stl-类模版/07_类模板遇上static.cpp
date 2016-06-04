
template<typename T>
class A {
public:
	static int m_a;
protected:
private:
	T a1;

};

template<typename T>
int A<T>::m_a=0;


#include "iostream"
using namespace std;

void main() {
	A<int> a1;
	A<int> a2;
	A<int> a3;

	A<char> b1;
	A<char> b2;
	A<char> b3;


	a1.m_a ++;
	b3.m_a = 199;
	cout<<a3.m_a<<endl;

	cout<<b2.m_a<<endl;


	system("pause");
}