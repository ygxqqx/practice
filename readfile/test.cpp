#include <iostream>
#include <cstring>
#include "stringCharacter.h"

char **readFile1(const char *pfilename, int *lineNum){
	int		len = 0;
	int		i = 0;
	char	**buf;
	char	redBuf[1024] = {0};
	if(pfilename == NULL){
		printf("pfilename null\n");
		return NULL;
	}

	FILE *fp = fopen(pfilename, "r");
	if(fp == NULL){
		printf("fopen null\n");
		return NULL;
	}
	else
		printf("open succ\n");
	
	while(!feof(fp)){
		memset(redBuf, 0, sizeof(redBuf));
		fgets(redBuf, 1023, fp);
		len++;
	}
	*lineNum = len;
	buf = (char **)malloc(len * sizeof(char *));
	if(buf == NULL){
		printf("buf null\n");
		return NULL;
	}
	fseek(fp, 0L, SEEK_SET);
	while(!feof(fp)){
		memset(redBuf, 0, sizeof(redBuf));
		fgets(redBuf, 1023, fp);
		int bufLen = sizeof(redBuf);
		buf[i] = (char *)malloc(bufLen * sizeof(char));
		if(buf[i] == NULL){
			printf("buf err\n");
			return NULL;
		}
		strcpy(buf[i], redBuf);
		//printf("%s\n", buf[i]);
		i++;
	}
	return buf;
}

int main(){
	
	char	**tem = NULL;
	char	*filename = "C:\\demo.cpp ";
	int		len = 0;

	tem =	readFile1(filename, &len);
	if(tem == NULL){
		printf("readFile1 err: \n");
	}
	else{
		printf("len: %d\n", len);
		int i;
		for(i=0; i < len; ++i){
			printf("%s\n", tem[i]);
		}
	}
	/*int ref;
	char *buf;
	//memset(buf, 0, sizeof(buf));
	stringCharacter ch;

	ref = ch.GetString_Adv(&buf);
	if(ref == 0){
		printf("GetString err:\n");
	}

	printf("buf is: %s\n",buf);*/
	
	system("pause");
}
