#include "stdlib.h"
#include "stdio.h"
#include "string.h"

//char *p = "abcd1111abcd222abcd3333" �����ҳ��ַ���abcd���ֵĴ���

//1����ڶ������
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
		if (p == NULL) //û���ҵ���������
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



//char *p = "abcd1111abcd222abcd3333" �����ҳ��ַ���abcd���ֵĴ���
//Ҫ��1�����Լ�����һ���ӿڣ�����������ʵ�ֹ��ܣ�70��
//Ҫ��2����д����������30��
/*
//���룺Ҫ���ҵ��ַ���
		�����ҵ��Ӵ�
			����Ľ��

			*/
//int cltClient_rev(void *handle, unsigned char *buf, int *buflen)
//��Ҫ���ű��˸��㴫�͵��ڴ��ַ�ǿ��õ�
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
		if (p == NULL) //û���ҵ���������
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
