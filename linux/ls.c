#include <dirent.h>
#include <stdio.h>
#include <unistd.h>

// 一个ls命令的简要实现

int main() {

    DIR *dir = NULL;

    dir = opendir("."); // 打开当前目录
    struct dirent * dp = NULL;
    if (dir != NULL) {
    	while ((dp = readdir(dir)) != NULL) {
    		printf("%s\n", dp->d_name);
    	}
    	closedir(dir);
    } else {
    	printf("error\n");
    }

	return 0;
}

