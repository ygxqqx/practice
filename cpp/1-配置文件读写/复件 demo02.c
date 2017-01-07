#include "stdio.h"
#include "stdlib.h"
#include "string.h"


/*
2 编写一个业务函数，实现按行读取文件。把内容按照第三种内存模型打包数据传出，把行数通过函数参数传出。
函数原型有两个，任意选择其一
要求1：请自己任意选择一个接口（函数），并实现功能；70分
要求2：编写测试用例。30分
要求3：自己编写内存释放函数
*/

int readFile2(const char *pfilename/*in*/, char ***p/*out*/, int *lineNum/*int out*/);


char **readFile1(const char *pfilename/*in*/, int *lineNum/*in out*/)
{
	int		rv = 0;
	FILE	*fp = NULL;
	char	 lineBuf[1024*4];
	
	char	**pTmp = NULL;
	char *p = NULL;
	int tmpLine = 0, strLine = 0, i = 0;

	if (pfilename==NULL || lineNum==NULL ) 
	{
		rv = -1;
		printf("readFile1() err. param err \n");
		goto End;
	}

	fp = fopen(pfilename, "r");
	if (fp == NULL)
	{
		rv = -2;
		printf("fopen() err. \n");
		goto End;
	}
	
	//第一遍 读取文件有多少行
	while (!feof(fp))
	{
		//读每一行
		memset(lineBuf, 0, sizeof(lineBuf));
		p = fgets(lineBuf, 1024*4, fp);
		if (p == NULL) 
		{
			break;
		}
		else
		{
			tmpLine ++;
		}
	}

	pTmp = (char **)malloc(tmpLine * sizeof(char *));
	if (pTmp == NULL)
	{
		rv = -2;
		printf("malloc() err. \n");
		goto End;
	}

	//让文件指针指向文件的开头，目的：第二次从头检索
	fseek(fp, 0L, SEEK_SET);
	
	//
	i = 0;
	while (!feof(fp))
	{
		//读每一行
		memset(lineBuf, 0, sizeof(lineBuf));
		p = fgets(lineBuf, 1024*4, fp);
		if (p == NULL) 
		{
			break;
		}

		strLine = strlen(lineBuf);
		pTmp[i] = (char *)malloc((strLine + 1) * sizeof(char));
		if (pTmp[i] == NULL)
		{
			rv = -3;
			printf("malloc() err. \n");
			goto End;
		}
		strcpy(pTmp[i], lineBuf);
		i++;
	}



End:
	if (fp != NULL)
	{
		fclose(fp); 
	}
	//赋值
	*lineNum = tmpLine;
	return pTmp;
}

void FreeMypp(char **p, int linenum)
{
	int i = 0;
	if (p == NULL)
	{
		return NULL;
	}
	for (i=0; i<linenum; i++)
	{
		if (p[i] != NULL)
		{
			free(p[i]) ;
		}
	}
	free(p);
	return ;
}

void main21()
{

	char				** mypp = NULL;
	const char		*pfilename = "c:/1.txt";
	int				lineNum = 0, i = 0;

	mypp = readFile1(pfilename/*in*/, &lineNum/*in out*/);
	if (mypp == NULL)
	{
		return ;
	}
	for (i=0; i<lineNum; i++)
	{
		printf("%s\n", mypp[i]);
	}

	system("pause");
}




int readFile1_Adv(const char *pfilename/*in*/,char ***myfileP, int *lineNum/*in out*/)
{
	int		rv = 0;
	FILE	*fp = NULL;
	char	 lineBuf[1024*4];

	char	**pTmp = NULL;
	char *p = NULL;
	int tmpLine = 0, strLine = 0, i = 0;

	if (pfilename==NULL || lineNum==NULL || myfileP==NULL) 
	{
		rv = -1;
		printf("readFile1() err. param err \n");
		goto End;
	}

	fp = fopen(pfilename, "r");
	if (fp == NULL)
	{
		rv = -2;
		printf("fopen() err. \n");
		goto End;
	}

	//第一遍 读取文件有多少行
	while (!feof(fp))
	{
		//读每一行
		memset(lineBuf, 0, sizeof(lineBuf));
		p = fgets(lineBuf, 1024*4, fp);
		if (p == NULL) 
		{
			break;
		}
		else
		{
			tmpLine ++;
		}
	}

	pTmp = (char **)malloc(tmpLine * sizeof(char *));
	if (pTmp == NULL)
	{
		rv = -2;
		printf("malloc() err. \n");
		goto End;
	}

	//让文件指针指向文件的开头，目的：第二次从头检索
	fseek(fp, 0L, SEEK_SET);

	//
	i = 0;
	while (!feof(fp))
	{
		//读每一行
		memset(lineBuf, 0, sizeof(lineBuf));
		p = fgets(lineBuf, 1024*4, fp);
		if (p == NULL) 
		{
			break;
		}

		strLine = strlen(lineBuf);
		pTmp[i] = (char *)malloc((strLine + 1) * sizeof(char));
		if (pTmp[i] == NULL)
		{
			rv = -3;
			printf("malloc() err. \n");
			goto End;
		}
		strcpy(pTmp[i], lineBuf);
		i++;
	}



End:
	if (fp != NULL)
	{
		fclose(fp); 
	}
	//赋值
	*lineNum = tmpLine;
	*myfileP = pTmp;
	return rv;
}

void main22()
{
	int				ret = 0;
	char				** mypp = NULL;
	const char		*pfilename = "c:/1.txt";
	int				lineNum = 0, i = 0;

	ret = readFile1_Adv(pfilename/*in*/, &mypp, &lineNum/*in out*/);
	if (ret != 0)
	{
		return ;
	}
	for (i=0; i<lineNum; i++)
	{
		printf("%s\n", mypp[i]);
	}
	 FreeMypp(mypp, lineNum);

	system("pause");
}


//
int readFile1_Adv3(const char *pfilename/*in*/,char ***myfileP/*in out*/)
{
	int		rv = 0;
	FILE	*fp = NULL;
	char	 lineBuf[1024*4];

	char	**pTmp = NULL;
	char *p = NULL;
	int tmpLine = 0, strLine = 0, i = 0;

	if (pfilename==NULL || myfileP==NULL) 
	{
		rv = -1;
		printf("readFile1() err. param err \n");
		goto End;
	}

	fp = fopen(pfilename, "r");
	if (fp == NULL)
	{
		rv = -2;
		printf("fopen() err. \n");
		goto End;
	}

	//第一遍 读取文件有多少行
	while (!feof(fp))
	{
		//读每一行
		memset(lineBuf, 0, sizeof(lineBuf));
		p = fgets(lineBuf, 1024*4, fp);
		if (p == NULL) 
		{
			break;
		}
		else
		{
			tmpLine ++;
		}
	}

	pTmp = (char **)malloc((tmpLine+1) * sizeof(char *));
	if (pTmp == NULL)
	{
		rv = -2;
		printf("malloc() err. \n");
		goto End;
	}
	memset(pTmp, 0, (tmpLine+1) * sizeof(char *));

	//让文件指针指向文件的开头，目的：第二次从头检索
	fseek(fp, 0L, SEEK_SET);

	//
	i = 0;
	while (!feof(fp))
	{
		//读每一行
		memset(lineBuf, 0, sizeof(lineBuf));
		p = fgets(lineBuf, 1024*4, fp);
		if (p == NULL) 
		{
			break;
		}

		strLine = strlen(lineBuf);
		pTmp[i] = (char *)malloc((strLine + 1) * sizeof(char));
		if (pTmp[i] == NULL)
		{
			rv = -3;
			printf("malloc() err. \n");
			goto End;
		}
		strcpy(pTmp[i], lineBuf);
		i++;
	}



End:
	if (fp != NULL)
	{
		fclose(fp); 
	}
	//赋值
	//*lineNum = tmpLine;
	*myfileP = pTmp;
	return rv;
}

void FreeMypp3(char **p)
{
	int i = 0;
	if (p == NULL)
	{
		return NULL;
	}
	for (i=0; p[i]!=NULL; i++)
	{
		if (p[i] != NULL)
		{
			free(p[i]) ;
		}
	}
	free(p);
	return ;
}

void main()
{
	int				ret = 0;
	char				** mypp = NULL;
	const char		*pfilename = "c:/1.txt";
	int				lineNum = 0, i = 0;

	ret = readFile1_Adv3(pfilename/*in*/, &mypp/*in out*/);
	if (ret != 0)
	{
		return ;
	}
	for (i=0; mypp[i]!=NULL; i++)
	{
		printf("%s\n", mypp[i]);
	}
	FreeMypp3(mypp);

	system("pause");
}


