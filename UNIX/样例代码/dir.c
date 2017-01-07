#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
main() {
	DIR *d;
	struct dirent *de;
	//打开目录
	d = opendir("/home");
	if (d == NULL) {
		printf("opendir:%m\n");
		exit(-1);
	}
	//循环读取目录
	while (de=readdir(d)) {
		printf("%s,\t%d\n",de->d_name,de->d_type);
	}
	
	//关闭目录
	closedir(d);
	
}
