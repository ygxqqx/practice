#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int getArray3_Free(char **p3, int p3num) {
	int i;
	if (p3 == NULL) {
		return -1;
	}
	for (i=0; i<p3num; i++) {
		if (p3[i]!=NULL) {
			free(p3[i]);
		}
	}
	free(p3);
}


int getArray3_Free2(char ***p3, int p3num) {
	int i;
	char **tmp = NULL;
	
	if (p3 == NULL) {
		return -1;
	}
	tmp = *p3;

	for (i=0; i<p3num; i++) {
		if (tmp[i]!=NULL) {
			free(tmp[i]);
		}
	}
	free(tmp);

	*p3 = NULL; //通过间接赋值，去间接的修改实参的值，成0
}

int getArray3_2(char **myp1, int num1, char (*myp2)[30], int num2, char ***myp3, int *num3) {
	int ret = 0;
	int i,j;
	int tmpNum3 = 0;
	char **tmpp3 = NULL;
	char *temp;

	if (myp1==NULL || myp2==NULL ||num3==NULL || myp3==NULL) {
		ret = -1;
		return ret;
	}
	//准备内存
	tmpNum3 = num1 + num2;
	//分配第一维
	tmpp3 = (char **)malloc(tmpNum3 * sizeof(char *));
	if (tmpp3 == NULL) {
		return NULL;
	}

	//分配第二维 把第一种内存模型数据和第二种内存模型数据,copy到第3中内存模型中
	for (i=0; i<num1; i++) {
		tmpp3[i] = (char *)malloc(strlen(myp1[i])+1);
		if (tmpp3[i]==NULL) {
			puts("out of space");
			return NULL;
		}
		strcpy(tmpp3[i],myp1[i]);
	}
	for (j=0; j<num2; j++,i++) {
		tmpp3[i]=(char *)malloc(strlen(myp2[j]) + 1); //note modify
		if (tmpp3[i]==NULL) {
			puts("out of space");
			return NULL;
		}
		strcpy(tmpp3[i],myp2[j]);
	}

	//排序
	for (i=0;i<tmpNum3;i++) {
		for (j=i+1;j<tmpNum3;j++) {
			if (strcmp(tmpp3[i],tmpp3[j])>0) {
				temp=tmpp3[i];
				tmpp3[i]=tmpp3[j];
				tmpp3[j]=temp;
			}
		}
	}

	//通过间接赋值，把结果甩给实参
	*num3=tmpNum3;
	*myp3 = tmpp3; //*0 = 100;
	return ret;
}

char **getArray3(char **myp1, int num1, char (*myp2)[30], int num2, int *num3) {
	int i,j;
	int tmpNum3 = 0;
	char **tmpp3 = NULL;
	char *temp;

	if (myp1==NULL || myp2==NULL ||num3==NULL ) {
		return NULL;
	}
	//准备内存
	tmpNum3 = num1 + num2;
	//分配第一维
	tmpp3 = (char **)malloc(tmpNum3 * sizeof(char *));
	if (tmpp3 == NULL) {
		return NULL;
	}
	
	//分配第二维 把第一种内存模型数据和第二种内存模型数据，copy到第3中内存模型中
	 for (i=0; i<num1; i++) {
	    tmpp3[i] = (char *)malloc(strlen(myp1[i])+1);
		if (tmpp3[i]==NULL) {
			puts("out of space");
			return NULL;
		}
		strcpy(tmpp3[i],myp1[i]);
	 }
	 for (j=0;j<num2;j++,i++) {
		 tmpp3[i]=(char *)malloc(strlen(myp2[j]) + 1); //note
		 if (tmpp3[i]==NULL) {
			 puts("out of space");
			 return NULL;
		 }
		 strcpy(tmpp3[i],myp2[j]);
	 }

	 //排序
	 for (i=0;i<tmpNum3;i++) {
		 for (j=i+1;j<tmpNum3;j++) {
			 if (strcmp(tmpp3[i],tmpp3[j])>0) {
				 temp=tmpp3[i];
				 tmpp3[i]=tmpp3[j];
				 tmpp3[j]=temp;
			 }
		 }
	 }
	
	 *num3=tmpNum3;
	return tmpp3;
}

void main() {
	int num3 = 0, i = 0; 
	int ret = 0;
	char *p1[] = {"222222", "1111111", "33333333"};
	char p2[4][30] =  {"bbbbb", "aaaaa", "zzzzzz", "ccccccc"};
	char **p3 = NULL;
	char ***myerrp3 = NULL;

	//p3 = getArray3(p1, 3, p2, 4, &num3);
	//ret = getArray3_2(p1,3, p2, 4, &p3, &num3);
	ret = getArray3_2(p1,3, p2, 4, 0, &num3); //错误做法
	if (ret != 0) {
		return ;
	}
	for (i=0; i<num3; i++) {
		printf("%s \n", p3[i]);
	}

	//getArray3_Free(p3, num3);
	//	p3=NULL;
	getArray3_Free2(&p3, num3);

	printf("p3:%d \n", p3);

	system("pause");
}