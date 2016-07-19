#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
	//一行一行读取数据
	int i = 0;
	FILE *fp = NULL;
	char buf[100];
	char *p = NULL;

	
	char *fname2 = "c:/demo.cpp"; //统一的用45度斜杠

	fp = fopen(fname2, "r"); //不管文件是否存在，新建文件
	if (NULL == fp) {
		printf("func fopen() err: \n");
	}

	while (!feof(fp)) {
		p = fgets(buf, 100, fp);
		if (p == NULL) {
			printf("func fgets() .....\n");
			break ;
		}
		printf("%s \n", buf); 
	}

	
	if (fp != NULL) {
		fclose(fp);
	}

	system("pause");
}