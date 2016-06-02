#include "stdlib.h"
#include "stdio.h"
#include "string.h"


//去掉空格后的字符串长度
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

//求去掉空格以后的有效长度长度mycount
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


//求去掉空格
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

//求去掉空格
//int trimSpaceStr2(char *p, unsigned char *buf2, int *buf2len) 
//不要轻易去改变指针输入特性中in内存块的内存。。。。
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

