#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
struct stu
{
	int no;
	char name[20];
	float score;
};
/*
1.判定文件是否存在,存在打开，不存在创建
2.输入记录
3.保存记录
4.提示继续输入
5.继续/不继续
6.关闭文件
*/
int openfile(const char *filename)
{
	int fd;
	fd=open(filename,O_RDWR|O_CREAT|O_EXCL,0666);
	if(fd==-1)//表示文件存在,则打开
	{
		fd=open(filename,O_RDWR|O_APPEND);
		return fd;
	}
	return fd;
}
void input(struct stu *record)
{
	bzero(record,sizeof(struct stu));
	printf("输入学号:");
	scanf("%d",&(record->no));
	printf("输入姓名:");
	scanf("%s",record->name);
	printf("输入成绩:");
	scanf("%f",&(record->score));
}
void save(int fd,struct stu *record)
{
	write(fd,record,sizeof(struct stu));
}
int iscontinue()
{
	char c;
	printf("是否继续输入:\n");
	//fflush(stdin);
	//fflush(stdout);
	scanf("\n%c",&c);	
	if(c=='Y' || c=='y')
	{
		return 1;
	}
	return 0;
}

int main()
{
	int fd;
	int r;
	struct stu s={0};
	fd=openfile("stu.dat");
	if(fd==-1) printf("openfile:%m\n"),exit(-1);
	
	while(1)
	{
		input(&s);
		save(fd,&s);
		r=iscontinue();
		if(r==0) break;
		system("clear");
	}
	close(fd);
	printf("输入完毕!\n");	
}
