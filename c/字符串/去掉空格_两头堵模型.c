#include "stdlib.h"
#include "stdio.h"
#include "string.h"


//ȥ���ո����ַ�������
void main41() {
	char *p = "     abcd     ";
	int ncount = 0;
	int i, j;
	i = 0;
	j = strlen(p) -1;

	while (isspace(p[i]) && p[i] != '\0') {
		i++;
	}

	while (isspace(p[j]) && j>0 ) {
		j--;
	}

	ncount = j - i + 1;

	printf("ncount:%d \n", ncount);

	system("pause");
}

//��ȥ���ո��Ժ����Ч���ȳ���mycount
int trimSpaceStr01(const char *p, int *mycount) {
	int ret = 0;

	int ncount = 0;
	int i, j;
	i = 0;
	j = strlen(p) -1;

	while (isspace(p[i]) && p[i] != '\0') {
		i++;
	}

	while (isspace(p[j]) && j>0 ) {
		j--;
	}

	ncount = j - i + 1;
	*mycount  = ncount;
	return ret;

}


//��ȥ���ո�
//int trimSpaceStr2(char *p, unsigned char *buf2, int *buf2len) 
int trimSpaceStr2(const char *p, char *buf2) {
	int ret = 0;

	int ncount = 0;
	int i, j;
	i = 0;
	j = strlen(p) -1;

	while (isspace(p[i]) && p[i] != '\0') {
		i++;
	}

	while (isspace(p[j]) && j>0 ) {
		j--;
	}

	ncount = j - i + 1;
	//
	strncpy(buf2, p+i, ncount);
	buf2[ncount] = '\0';
	return ret;
}

//��ȥ���ո�
//int trimSpaceStr2(char *p, unsigned char *buf2, int *buf2len) 
//��Ҫ����ȥ�ı�ָ������������in�ڴ����ڴ档������
int trimSpaceStr2_notgood( char *p) {
	int ret = 0;

	int ncount = 0;
	int i, j;
	i = 0;
	j = strlen(p) -1;

	while (isspace(p[i]) && p[i] != '\0') {
		i++;
	}

	while (isspace(p[j]) && j>0 ) {
		j--;
	}

	ncount = j - i + 1;
	//
	strncpy(p, p+i, ncount);
	p[ncount] = '\0';
	return ret;
}

void main() {
	char buf[] = "     abcd     ";
	char buf2[1024] = {0};
	//memset(buf2, 0, sizeof(buf2));
	{
		char buf3[] = "     abcd     ";
		trimSpaceStr2_notgood(buf3);

	}

	{
		char *p =  "     abcd     ";
		trimSpaceStr2_notgood(p);
	}
	
	//printf("buf2:%s \n", buf2);
}

