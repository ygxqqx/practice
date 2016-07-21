#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

void main03() {
	int i = 0;
	FILE *fp = NULL;
	char a[100] = "abcdefghijkddddsssss";

	//char *fname = "c:\\1.txt";
	char *fname2 = "c:/a1.txt"; //统一的用45度斜杠

	fp = fopen(fname2, "r+"); //r+ 读写文件，文件必须存在
	if (NULL == fp) {
		printf("func fopen（） err: %s \n", fname2);
		return ;
	}

	fputs(a, fp);

	if (fp != NULL) {
		fclose(fp);
	}


	system("pause");
}

char * myfgets(char *mybuf, int nMax, FILE *fp) {

	if (fp == NULL) {
		return NULL;
	}
	strcpy(mybuf, "aaaaa");
	
	//
	return mybuf;
}

void main04() {
	int i = 0;
	FILE *fp = NULL;
	char buf[100];
	char *p = NULL;

	char *fname = "c:\\1.txt";
	char *fname2 = "c:/a1.txt"; //统一的用45度斜杠

	fp = fopen(fname2, "r"); //不管文件是否存在，新建文件
	if (NULL == fp) {
		printf("func fopen（） err: \n");
	}

	while (!feof(fp)) {
		//_cdecl fgets(_Out_z_cap_(_MaxCount) char * _Buf, _In_ int _MaxCount, _Inout_ FILE * _File);
		p = fgets(buf, 100, fp);
		if (p == NULL) {
			printf("func fgets() .....\n");
			return ;
		}
		printf("%s \n", buf);
		printf("%s \n", p); 
	}

	
	if (fp != NULL) {
		fclose(fp);
	}



}

void main() {
	//main03();
	main04();
	system("pause");
}