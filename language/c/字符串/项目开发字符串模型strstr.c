#include "stdlib.h"
#include "stdio.h"
#include "string.h"

//char *p = "abcd1111abcd222abcd3333" 请你找出字符串abcd出现的次数

//1个入口多个出口
void main01()
{
	char *str1 = "Borland International", *str2 = "Xnation", *ptr;
	ptr = strstr(str1, str2);
	
	if (ptr == NULL)
	{
		return;
	}
	printf("The substring is: %s\n", ptr);
	system("pause");
}





void main33()
{
	char *p = "abcd1111abcd222abcd3333";
	int ncout = 0;
	do 
	{
		p = strstr(p, "abcd");
		if (p == NULL) //没有找到则跳出来
		{
			break;
		}
		else 
		{
			ncout++;
			p = p + strlen("abcd");
		}
		
	} while (*p != '\0');
	printf("ncout:%d\n", ncout);
	system("pause");
	
}



//char *p = "abcd1111abcd222abcd3333" 请你找出字符串abcd出现的次数
//要求1：请自己定义一个接口（函数），并实现功能；70分
//要求2：编写测试用例。30分
/*
//输入：要查找的字符串
		待查找的子串
			输出的结果

			*/
//int cltClient_rev(void *handle, unsigned char *buf, int *buflen)
//不要相信别人给你传送的内存地址是可用的
int getCout(char *str, char *substr, int *count)
{

	int rv = 0;
	char *p = str;
	
	int ncout = 0;
	if (str==NULL || substr== NULL ||  count==NULL)
	{
		rv = -1;
		printf("func getCout()check (str==NULL || substr== NULL ||  count==NULL) err:%d \n" , rv);
		return rv;
	}

	do 
	{
		p = strstr(p, substr);
		if (p == NULL) //没有找到则跳出来
		{
			break;
		}
		else 
		{
			ncout++;
			p = p + strlen(substr);
		}

	} while (*p != '\0');

	//fuzhi 
	*count  = ncout;
	
	printf("ncout:%d\n", ncout);
	return rv;

}

void main()
{
	int ret = 0;
	//char *p = "abcd1111abcd222abcd3333";
	char *p = NULL;
	int ncout = 0;
	char *subp = "abcd";

	ret = getCout(p, subp, &ncout);
	if (ret != 0)
	{
		printf("func getCout() err:%d \n", ret);
		return ;
	}
	printf("coutn:%d \n", ncout);
	system("pause");

}
