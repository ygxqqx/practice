#include "string.h"
#include "stdio.h"
#include "stdlib.h"

//������д�������
int add(int a, int b) {
	int c ;
	c = a + b;
	printf("func add:%d \n", c);
	return c;
}

int add2(int a, int b) {
	int c ;
	c = a + b;
	printf("func add:%d \n", c);
	return c;
}

//�����������
int MyOP(int (*MyAdd)(int, int)) {
	//ִ��add����������2�ַ���
	add(1, 2);
	MyAdd(3, 4);
	return 0;
}
//��������һ�����ͣ�����һ������ָ�����͡�����
typedef int(*PMyFuncType)(int , int);
//����ָ�������������ı��ʡ�
//1�������ǰѺ�����ڵ�ַ�����͸������ú�������
//2��ͬʱ���������ͣ�Ҳ����һ���ӿڵ�Լ�����������������������͵�Լ����
//��ӳ�������ϡ�����������Ҫ�� ������������ֵ��ͳͳ������һ��Լ����������
//����ͺ���ָ�������������ĺ���˼�롣����

//�Աȣ�C++
	//
int MyOP2(PMyFuncType pMyFuncType) {
	//ִ��add����������2�ַ���
	add(1, 2);
	pMyFuncType(3, 4);
	return 0;
}

//����������ˣ����ֿ��ˡ�����������
void main() {

	//����һ��ָ�����������ָ�����
	int (*pAdd)(int , int); 
	//�Ѻ�������ڵ�ַ���Ƹ���������pAdd
	pAdd = add;
	//����MyOP��Ҫ����һ������ָ�����͡����ı���������
	//MyOP(pAdd);
	MyOP2(add2);
	system("pause");
}