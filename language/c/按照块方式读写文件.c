#include "stdio.h"
#include "string.h"
#include "stdlib.h"

/*
unsigned char c ; //0-255
 char c //0 -127
int sckClit_sen(void *hanle, unsigned char *buf, int buflen)
//�ļ��ڴ����ϵĴ�������ַ�ʽ asc��ʽ���Ե� ����asc��bin��ʽ��
*/
typedef struct Student_
{    
	char name[10];
	int num;
	int age;
	char addr[15];
}Student;

#define SIZE 5 

void main5()
{  
	int  i;
	FILE *fp = NULL;

	Student student[5];

	if((fp=fopen("c:/student.data","wb"))==NULL)
	{    
		printf("cannot open file\n");
		return;
	}

	for (i=0; i<5; i++)
	{
		memset(&student[i], 0, sizeof(Student));
		sprintf(student[i].name, "name%d", i+1);

		//�ѵڶ���������ϵ��ַ�������ӡ����һ������buf�С�
		//sprintf(student[i].name,"name%d", i+1);
		//fprintf(fp,"name%d", i+1);
	}

	for(i=0;i<5;i++)
	{
		if(fwrite(&student[i],sizeof(Student),1,fp)!=1)
			printf("file write error\n");
	}

	fclose(fp);

}


void display()
{   
	FILE *fp;
	int  i;

	Student student[SIZE];
	for (i=0; i<SIZE; i++)
	{
		memset(&student[i], 0, sizeof(Student));
		//sprintf(student[i].name, "name%d", i+1);
	}

	if((fp=fopen("c:/student.data","rb"))==NULL)
	{    
		printf("cannot open file\n");
		return;
	}

	for(i=0;i<SIZE;i++)
	{   
		fread(&student[i],sizeof(Student),1,fp);
		printf("%-10s %4d %4d %-15s\n",student[i].name,
			student[i].num,student[i].age,student[i].addr);
	}
	fclose(fp);
}

int main()
{

	main5();
	display();

	getchar();
	return 0;
}