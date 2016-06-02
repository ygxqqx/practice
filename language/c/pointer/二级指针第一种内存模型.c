#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int printAarray(char **pArray, int num) {
	int i = 0;
	
	if (pArray == NULL) {
		return -1;
	}

	for (i=0; i<num; i++) {
		printf("%s \n", pArray[i]);
	}

	return 0;
}

int sortArray(char **pArray, int num) {
	char *tmp = NULL;
	int i = 0, j = 0;
	
	if (pArray == NULL) {
		return -1;
	}
	for (i=0; i<num; i++) {
		for (j=i+1; j<num; j++) {
			if (strcmp(pArray[i], pArray[j]) > 0) {
				//������������Ԫ�� ����Ԫ����ָ��
				tmp = pArray[i];
				pArray[i] = pArray[j];
				pArray[j] = tmp;
			}
		}
	}
}
void main() {
	char *tmp = NULL;
	int i = 0, j = 0;
	//����ָ���һ���ڴ�ģ��
	//���ȿ�������һ�����飬ָ�����飬====��ֻ����ÿһ��Ԫ����ָ����ѡ�
	//�������ȼ��� 
	//��ӡ���� ��������������顢������ָ������������
	char * myArray[] = {"bbbbb", "aaaa", "ccccc", "1111111"};

	printf("����֮ǰ\n");
	printAarray(myArray, 4);

	sortArray(myArray, 4);


	printf("����֮��\n");
	printAarray(myArray, 4);

	system("pause");
}