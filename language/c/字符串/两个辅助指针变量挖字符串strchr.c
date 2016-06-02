#include "stdio.h"
#include "string.h"
#include "stdlib.h"

/*
有一个字符串符合以下特征（”abcdef,acccd,eeee,aaaa,e3eeeee,sssss,";）,
要求写一个函数（接口），输出以下结果
	1）	以逗号分割字符串，形成二维数组，并把结果传出；
	2）	把二维数组行数运算结果也传出。
	strchr(“aa,aa”,’,’ );
请自己定义一个接口（函数）。
	要求1：能正确表达功能的要求，定义出接口（函数）（30分）；
	要求2：正确实现接口（函数），并实现功能（40分）；
	要求3：编写正确的测试用例。（30分）。
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

	//步骤1 初始化条件 pTmp,p都执行检索的开头
	p = buf1;
	pTmp = buf1;
	do {
		//步骤2 strstr strchr，会让p后移 	在p和pTmp之间有一个差值
		p = strchr(p, c);
		if (p == NULL) {//没有找到则跳出来
			break;
		}
		else {
			memset(myBuf, 0, sizeof(myBuf));
			
			//挖字符串
			strncpy(myBuf, pTmp, p-pTmp);
			myBuf[p-pTmp] = '\0';

			strcpy(buf[ncount], myBuf);

			ncount++;
			//步骤3 让p和pTmp重新初始化，达到检索的条件 
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
	//步骤1 初始化条件 pTmp,p都执行检索的开头
	p = buf1;
	pTmp = buf1;
	do {
		//步骤2 strstr strchr，会让p后移 	在p和pTmp之间有一个差值
		p = strchr(p, c);
		if (p == NULL) {//没有找到则跳出来
			break;
		} else {

			//挖字符串
			strncpy(buf[ncount], pTmp, p-pTmp);
			buf[ncount][p-pTmp] = '\0';

			ncount++;

			//步骤3 让p和pTmp重新初始化，达到检索的条件
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
