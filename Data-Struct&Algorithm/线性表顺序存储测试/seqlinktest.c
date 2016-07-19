#include <stdio.h>
#include "stdlib.h"
#include "string.h"

#include "seqlist.h"

typedef struct _Teacher
{
	char name[64];
	int age;
}Teacher;


typedef struct _tag_SeqList
{
	int capacity;
	int length;
	unsigned int *node; //unsigned int array[capacity]
}TSeqList;

//
int main()
{
	int i = 0;
	SeqList *list = NULL;

	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;

	list =  SeqList_Create(10);
	SeqList_Create01(&list, 10);

	//ͷ�巨
	//ʵ���ˣ�ҵ������ �� �����㷨�ķ��롣������
	SeqList_Insert(list, (SeqListNode*)&t1, 0);
	SeqList_Insert(list, (SeqListNode*)&t2, 0);
	SeqList_Insert(list, (SeqListNode*)&t3, 0);

	//ѭ������
	for (i=0; i<SeqList_Length(list); i++)
	{
		Teacher *tmp = (Teacher *) SeqList_Get(list, i);
		if (tmp != NULL)
		{
			printf("tmp:age:%d ", tmp->age);
		}
	}

	//ѭ��ɾ��

	for (i=0; i<SeqList_Length(list); i++)
	{
		SeqList_Delete(list, 0);
	}
	SeqList_Destroy(list);

	system("pause");
}