#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
main()
{
	DIR *d;
	struct dirent *de;
	//��Ŀ¼
	d=opendir("/home");
	if(d==NULL)
	{
		printf("opendir:%m\n");
		exit(-1);
	}
	//ѭ����ȡĿ¼
	while(de=readdir(d))
	{
		printf("%s,\t%d\n",de->d_name,de->d_type);
	}
	
	//�ر�Ŀ¼
	closedir(d);
	
}
