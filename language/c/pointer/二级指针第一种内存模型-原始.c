#include "stdio.h"
#include "string.h"
#include "stdlib.h"


void main1111()
{
	char* tmp = NULL;
	int i = 0, j = 0;
	//����ָ���һ���ڴ�ģ��
	//���ȿ�������һ�����飬ָ�����飬====��ֻ����ÿһ��Ԫ����ָ����ѡ�
	//�������ȼ��� 
	//��ӡ���� ��������������顢������ָ������������
	//
	char * myArray[4] = {"bbbbb", "aaaa", "ccccc", "1111111"};
	sizeof(myArray); //myArray�Ƕ���ָ���int a[10]һ��ָ�벻һ��
	
	{
		int num1 = sizeof(myArray)/sizeof(myArray[0]);
		int num2 = sizeof(myArray)/sizeof(*myArray);
		printf("num1:%d, num2:%d \n", num1, num2);
	}

	printf("����֮ǰ\n");
	for (i=0; i<4; i++)
	{
		printf("%s \n", myArray[i]);
	}

	for (i=0; i<4; i++)
	{
		for (j=i+1; j<4; j++)
		{
			if (strcmp(myArray[i], myArray[j]) > 0)
			{
				//������������Ԫ�� ����Ԫ����ָ��
				tmp = myArray[i];
				myArray[i] = myArray[j];
				myArray[j] = tmp;
			}
		}
	}

	printf("����֮��\n");
	for (i=0; i<4; i++)
	{
		printf("%s \n", myArray[i]);
	}

	system("pause");
}

int main()
{
	int a[10]; //a����������Ԫ�صĵ�ַ 
	main1111();
	printf("sizeof(a[10]):%d\n" , sizeof(a)); //4
	printf("&a:%d\n" , sizeof(&a)); //40

}