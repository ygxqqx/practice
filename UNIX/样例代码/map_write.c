#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/mman.h>
struct stu
{
	char name[20];
	int  age;
	float score;
};
main()
{
	int fd;
	struct stu *s;//�ļ��������ڴ��ӳ���׵�ַ
	struct stat st;
	int size;//�ļ���С
	int count;//��¼����
	int i;
	//1.���ļ�
	fd=open("newstu.dat",O_RDWR|O_CREAT|O_EXCL,0666);
	if(fd==-1)
	{
		fd=open("newstu.dat",O_RDWR);
		if(fd==-1) printf("::%m\n"),exit(-1);
	}
	//2.�õ��ļ���С���ļ���¼����
	fstat(fd,&st);
	size=st.st_size;
	count=size/sizeof(struct stu);
	//3.�ļ���С�ı�ֻҪ��munmap֮ǰ���ö���Ч	
	//ftruncate(fd,size+sizeof(struct stu));
	//4.ӳ�䵽һ������ĵ�ַ
	s=mmap(0,size+sizeof(struct stu),
				PROT_READ|PROT_WRITE,
				MAP_SHARED,fd,0);
	//5.������д�������ַ
	/*
	printf("��������:");
	scanf("%s",s[count].name);
	printf("��������:");
	scanf("%d",&(s[count].age));
	printf("����ɼ�:");
	scanf("%f",&(s[count].score));
	ftruncate(fd,size+sizeof(struct stu));
	*/
	for(i=0;i<count;i++)
	{
		printf("%s,\t,%d,\t%.2f\n",
			s[i].name,s[i].age,s[i].score);
	}	
	//6.ж�������ַ
	munmap(s,sizeof(struct stu)+size);
	//7.�ر��ļ�
	close(fd);
}
