#include "string.h"
#include "stdio.h"
#include "stdlib.h"

//���һ����������
//���һ������ָ�������
//��ζ���һ��ָ���������͵�һ��ָ�����

void main_�������ͻ���() {
	//int array[10];
	//���һ����������

	typedef int (MyArrayType)[10];

	MyArrayType myArray; ////int array[10];
	myArray[0] = 1;

	{
		//���һ������ָ�������
		int array2[10];
		typedef int (*PMyArrayType)[10];
		PMyArrayType  pmyArray;
		pmyArray = &pmyArray;
		(*pmyArray)[0] = 11;

		{
			 int a = 10;
			 int *p = NULL;
			 p = &a;
		}
	}

	{
		int array3[10];
		int (*pM)[10]; //������һ��ָ�����������c���������ҷ���4���ֽڵ��ڴ棬�����ָ�����ָ��һ�����顣
		//����֮���ǣ�pM++�����һ�����鵥λ����������4*10�����ֽ�

		pM = &array3;
		(*pM)[0] = 12;
		printf("%d \n",array3[0] );

	}

	system("pause");
}

//���庯������
//���庯��ָ������
//����һ��ָ�뺯����ָ�����

//test�Ǻ��������������������׵�ַ�����������Ǻ���ָ�� 
int test(int a) {
	printf("a:%d", a);
	return 0;
}
void main() {
	//����һ���������͡�����
	typedef int (MYFuncType)(int);
	MYFuncType *myfun; //����ָ�����
	test(1); //ָ��һ����������

	{
		myfun = test;
		//ͨ������ָ������������ҵ�������ڣ�����ִ�к���
		myfun(2);
	}
	{
		//�Ժ�������&��ַ���Ͳ�ȡ��ַ��Ч��һ����������
		//��ʷ����ԭ��
		myfun = &test;
		myfun(3);
	}

	{
		int ret = 0;
		//������һ������ָ������
		typedef int (*PMYFuncType)(int);
		PMYFuncType  pMyFuncType;

		pMyFuncType = test;
		ret = pMyFuncType(1);
	}

	{
		//ֱ�Ӷ���һ������ָ�������������
		int (*PmyFunc)(int) ; //���߱���������4���ֽ�
		PmyFunc = test;
		PmyFunc(11);

	}
	//printf("myFunc:%d", sizeof(myFunc));
	system("pause");
}