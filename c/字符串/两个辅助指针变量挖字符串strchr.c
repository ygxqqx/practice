#include "stdio.h"
#include "string.h"
#include "stdlib.h"

/*
��һ���ַ�������������������abcdef,acccd,eeee,aaaa,e3eeeee,sssss,";��,
Ҫ��дһ���������ӿڣ���������½��
	1��	�Զ��ŷָ��ַ������γɶ�ά���飬���ѽ��������
	2��	�Ѷ�ά��������������Ҳ������
	strchr(��aa,aa��,��,�� );
���Լ�����һ���ӿڣ���������
	Ҫ��1������ȷ��﹦�ܵ�Ҫ�󣬶�����ӿڣ���������30�֣���
	Ҫ��2����ȷʵ�ֽӿڣ�����������ʵ�ֹ��ܣ�40�֣���
	Ҫ��3����д��ȷ�Ĳ�����������30�֣���
	*/
//abcdef,acccd,eeee,aaaa,e3eeeee,sssss,
/*
abcdef
	acccd 
	eeee,
	aaaa,
	e3eeeee,
	sssss,
	*/

int spitString(const char *buf1, char c, char buf[10][30], int *num) {
	char *p = NULL;
	char *pTmp = NULL;
	int ncount = 0;
	char myBuf[1024] = {0};

	//����1 ��ʼ������ pTmp,p��ִ�м����Ŀ�ͷ
	p = buf1;
	pTmp = buf1;
	do {
		//����2 strstr strchr������p���� 	��p��pTmp֮����һ����ֵ
		p = strchr(p, c);
		if (p == NULL) {//û���ҵ���������
			break;
		}
		else {
			memset(myBuf, 0, sizeof(myBuf));
			
			//���ַ���
			strncpy(myBuf, pTmp, p-pTmp);
			myBuf[p-pTmp] = '\0';

			strcpy(buf[ncount], myBuf);

			ncount++;
			//����3 ��p��pTmp���³�ʼ�����ﵽ���������� 
			pTmp = p  = p + 1;
		}

	} while (*p != '\0');
	//printf("ncout:%d\n", ncount);
	*num = ncount;
	return 0;
}

int spitString02(const char *buf1, char c, char buf[10][30], int *num) {
	int ret = 0;
	char *p = NULL;
	char *pTmp = NULL;
	int ncount = 0;
	if (buf1==NULL ||  num==NULL) {
		return -1;
	}
	//����1 ��ʼ������ pTmp,p��ִ�м����Ŀ�ͷ
	p = buf1;
	pTmp = buf1;
	do {
		//����2 strstr strchr������p���� 	��p��pTmp֮����һ����ֵ
		p = strchr(p, c);
		if (p == NULL) {//û���ҵ���������
			break;
		} else {

			//���ַ���
			strncpy(buf[ncount], pTmp, p-pTmp);
			buf[ncount][p-pTmp] = '\0';

			ncount++;

			//����3 ��p��pTmp���³�ʼ�����ﵽ����������
			pTmp = p  = p + 1;
		}

	} while (*p != '\0');
	//printf("ncout:%d\n", ncount);
	*num = ncount;
	return ret;
}
void main() {
	int ret = 0, i = 0;
	const char *buf1 = "abcdef,acccd,";
	char c = ',';
	char buf[10][30];
	int num = 0;
	ret =  spitString02(buf1, c, buf, &num);
	if (ret != 0) {
		printf("func spitString() err:%d\n", ret);
		return ret;
	}

	for (i=0; i<num; i++) {
		printf("%s\n", buf[i]);
	}

	system("pause");
}
