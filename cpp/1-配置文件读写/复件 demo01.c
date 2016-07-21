#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/*
1 编写一个业务函数，实现字符串（前后各有三个空格，单词前后也均有空格）
	"   i am student, you are teacher   " ，
	各个单词首字符大写，结果如下"   i am student,  you are teacher   " ，
	要求1：实现所有接口  70
	要求2：写出测试程序  30
	*/



int GetString_Adv(const char *str1/*in*/, char **str2 /*out*/);


int GetString(const char *str1 /*in*/, char *str2 /*in*/)
{
	int ret = 0;
	char *p1 = NULL, *p2 = NULL;
	int len = 0, i = 0;

	if (str1 == NULL || str2==NULL )
	{
		ret = -1;
		return ret;
	}
	len = strlen(str1);

	//
	strcpy(str2, str1);

	//初始化循环环境
	p1 = str2 +1 ;
	p2 = str2;
	for (i=0; i<len && (*p1!= NULL) ; i++)
	{
		if  (isalpha(*p1) && isspace(*p2))
		{
			*p1 = *p1 - 32;
		}

		//打造循环条件
		p2 = p1;
		p1 ++;
	}

	return ret;
}



void main01()
{
	int ret = 0;
	const char *str1 = "     i am student, you are teacher   ";
	char buf[1024] = {0};

	ret = GetString(str1 /*in*/, buf /*in*/);
	if (ret != 0)
	{
		printf("func GetString() err:%d \n", ret);
		return ret;
	}
	printf("buf:%s \n", buf);

	system("pause");
}

int GetString_Adv(const char *str1/*in*/, char **str2 /*out*/)
{
	int ret = 0;
	char *p1 = NULL, *p2 = NULL;
	char *ptmp = NULL;
	int len = 0, i = 0;

	if (str1 == NULL || str2==NULL )
	{
		ret = -1;
		return ret;
	}
	len = strlen(str1);

	ptmp = (char *)malloc((len+1) * sizeof(char));
	if (ptmp == NULL)
	{
		ret = -2;
		return ret;
	}
	memset(ptmp, 0, (len+1) * sizeof(char));
	//
	strcpy(ptmp, str1);

	//初始化循环环境
	p1 = ptmp +1 ;
	p2 = ptmp;
	for (i=0; i<len && (*p1!= NULL) ; i++)
	{
		if  (isalpha(*p1) && isspace(*p2))
		{
			*p1 = *p1 - 32;
		}

		//打造循环条件
		p2 = p1;
		p1 ++;
	}
	*str2 = ptmp; //str2是实参的地址 间接赋值修改实参，让实参指向新分配的内存空间
	return ret;
}

int GetString_Adv_Free1(char *str2)
{
	if (str2 == NULL)
	{
		return -1;
	}
	free(str2);
	str2 = NULL; //垃圾语句
}

int GetString_Adv_Free2(char **                  str2)
{
	char *tmp = NULL;
	if (str2 == NULL)
	{
		return -2;
	}
	tmp = *str2;
	if (tmp != NULL)
	{
		free(tmp);
		*str2 = NULL;
	}
}

void main12()
{
	int ret = 0;
	const char *str1 = "     i am student, you are teacher   ";
	//char buf[1024] = {0};
	char *pbuf = NULL;
	ret = GetString_Adv(str1 /*in*/, &pbuf /*in*/);
	if (ret != 0)
	{
		printf("func GetString() err:%d \n", ret);
		return ret;
	}
	printf("pbuf:%s \n", pbuf);

	GetString_Adv_Free2(&pbuf);


	system("pause");
}