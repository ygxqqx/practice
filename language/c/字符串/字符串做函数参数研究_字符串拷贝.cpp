#include "stdlib.h"
#include "stdio.h"
#include "string.h"


//自定义：字符串copy函数，完成字符串from ，到to的copy
void copy_str1(char *from, char *to)
{
	for (; *from!='\0'; from++, to++)
	{
		*to = *from;
	}
	*to = '\0';
}


void copy_str2(char *from, char *to)
{
	while(*from!='\0')
	{
		*to = *from;
		from++;
		to++;
	}
	*to = '\0';
}

//++优先级高,dan是++是后缀++
//所以先执行*to = *from; 再 from++; to ++from++;
void copy_str3(char *from, char *to)
{
	while(*from!='\0')
	{
		*to ++ = *from ++;
	}
	*to = '\0';
}

void copy_str4_1(char *from, char *to)
{
	while((*to = *from) !='\0')
	{
		to++;
		from++;
	}
}
void copy_str4_2(char *from, char *to)
{
	while((*to++ = *from++) !='\0')
	{
		;
	}
}

void copy_str5(char *from, char *to)
{
	while((*to++ = *from++))
	{
		;
	}
}

void main()
{
	char *p = "abcdefg";
	//char *p2 = NULL;
	char p2[100] ;
	copy_str5(p, p2);

	//strcpy(p2, "abcdeeg");
	printf("p2:%s\n", p2);

	system("pause");
}