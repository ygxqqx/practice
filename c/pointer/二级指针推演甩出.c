#include "stdlib.h"
#include "string.h"
#include "stdio.h"


int getMem(char ***myp3 /*out*/) {
	int i = 0;

	char **tmp = (char **)malloc(10*sizeof(char *));
	if (tmp == NULL) {
		return -1;
	}
	memset(tmp, 0, 10*sizeof(char *));
	for (i=0; i<3; i++) {
		tmp[i] = (char *)malloc(100);
	}
	//*myp3 = 100; //p2ȡ��ַ����p3 ͨ��*p3��p2�ĵ�ַ��ȥ��ӵ��޸���p2��ֵ����
	*myp3 = tmp;
	return;
}


void main() {
	char **p2 = NULL;
	char ***p3 = NULL;
	
	//ֱ���޸�p2 ��ֵ
	p2 = 1;
	p2 = 3;

	printf("p2:%d \n", p2);
	p3 = &p2;
	*p3 = 100; //p2ȡ��ַ����p3 ͨ��*p3��p2�ĵ�ַ��ȥ��ӵ��޸���p2��ֵ����

	//p3 = &p2;
	getMem(&p2);

	printf("p2:%d \n", p2);
	system("pause");
}