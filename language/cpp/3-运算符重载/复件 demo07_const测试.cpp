#include "iostream"
using namespace std;

//C 
class Test
{
public:
protected:
private:
	int a;
	const int A() //const // ====>int A(const this) 
	{ 
		//�۵�1��const������a,����ͨ�����ԣ����Ƿ��֣�b++Ҳ���ܱ���ͨ��
		//��˵����const��a �� b�������ˡ�������

		//��������Ϊthis��Ϊ�����ĵ�һ�������������ء�������constû�еط��š�������
		//
		//const������this

		a ++;
		//b++;
		return a; 
	}
	void A(int val) 
	{ 
		a = val; 
	}

	int BBB()
	{
		
		return a;
	}

	int b;
};


 int Aaaaa(const Test *pthis) 
{ 
	return 10; 
}
void main()
{
	Test t1;
	system("pause");
}