#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/*
4、从键盘中输入一个不超过40个字符的字符串，再输入3个位数（每次删除一个字符），
删除对应 位数的字符，然后输出删除指定字符后的字符串。
	输入：hellokityManGood  
	3  6   9
	helokityManGood  

	heloktyManGood  

	heloktyMnGood  
*/
int delAlpa(char *p, int pos)
{
	int len = 0;
	int i = 0;
	if (p == NULL)
	{
		return -1;
	}
	len = strlen(p);

	if (pos >= len)
	{
		return -2;
	}
	//pos位置从0开始
	for (i=pos; i<len; i++)
	{
		p[i] = p[i+1];
	}
	p[len-1] = '\0';
	return 0;
}

void main()
{
	int ret = 0;

	char str[] = "hellokityManGood";
	ret = delAlpa(str, 3);
	if (ret != 0)
	{
		printf("func delAlpa() err:%d \n",ret);
		return ret;
	}
	printf("str:%s \n", str);
	ret = delAlpa(str, 6);
	if (ret != 0)
	{
		printf("func delAlpa() err:%d \n",ret);
		return ret;
	}
	printf("str:%s \n", str);
	ret = delAlpa(str, 9);
	if (ret != 0)
	{
		printf("func delAlpa() err:%d \n",ret);
		return ret;
	}
	printf("str:%s \n", str);

	system("pause");
}