#include "iostream"
using namespace std;

class AA {
public:
	AA() {
		//�޲ι��캯�� Ĭ�Ϲ��캯��	
		cout<<"���ǹ��캯�����Զ���������"<<endl;
	}
	AA(int _a) {
		//�޲ι��캯�� Ĭ�Ϲ��캯��	
		a = _a;
	}

	~AA() {

		cout<<"���������������Զ���������"<<endl;
	}
	void getA() {

		printf("a:%d \n", a);
	}
protected:
private:
	int a;
};

//�����һ����̨
void ObjPlay01() {

	AA a1; //��������
	
	//��ֵ���캯���ĵ�һ��Ӧ�ó���
	//���ö���1 ��ʼ�� ����2 
	AA a2 = a1; //�����������ʼ��

	a2 = a1; //��a1��=�Ÿ�a2 �������������ṩ��ǳcopy
}

//�����һ����̨
void ObjPlay02() {

	AA a1(10); //��������

	//��ֵ���캯���ĵ�һ��Ӧ�ó���
	//���ö���1 ��ʼ�� ����2 
	AA a2(a1); //�����������ʼ��

	//a2 = a1; //��a1��=�Ÿ�a2 �������������ṩ��ǳcopy
	a2.getA();
}

void main() {
	
	ObjPlay02();
	system("pause");
}