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
1.�ж��ļ��Ƿ����,���ڴ򿪣������ڴ���
2.�����¼
3.�����¼
4.��ʾ��������
5.����/������
6.�ر��ļ�
*/
int openfile(const char *filename)
{
	int fd;
	fd=open(filename,O_RDWR|O_CREAT|O_EXCL,0666);
	if(fd==-1)//��ʾ�ļ�����,���
	{
		fd=open(filename,O_RDWR|O_APPEND);
		return fd;
	}
	return fd;
}
void input(struct stu *record)
{
	bzero(record,sizeof(struct stu));
	printf("����ѧ��:");
	scanf("%d",&(record->no));
	printf("��������:");
	scanf("%s",record->name);
	printf("����ɼ�:");
	scanf("%f",&(record->score));
}
void save(int fd,struct stu *record)
{
	write(fd,record,sizeof(struct stu));
}
int iscontinue()
{
	char c;
	printf("�Ƿ��������:\n");
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
	printf("�������!\n");	
}
