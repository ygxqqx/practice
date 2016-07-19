#include<stdio.h>
#include "stdlib.h"
#include "string.h"
#include "linklist.h"

typedef struct Teacher
{
	LinkListNode node;
	char name[64];
	int age;
}Teacher;

int main()
{
	Teacher		t1,t2, t3;
	int			length, i = 0;

	LinkList		*list = NULL;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;


	list = LinkList_Create();

	length = LinkList_Length(list);

	//ҵ��ڵ���teacher���㷨����ġ�������˼��
	LinkList_Insert(list, (LinkListNode *)&t1, LinkList_Length(list));
	LinkList_Insert(list, (LinkListNode *)&t2, LinkList_Length(list));
	LinkList_Insert(list, (LinkListNode *)&t3, LinkList_Length(list));

	//�������� 
	for (i=0; i<LinkList_Length(list); i++)
	{
		Teacher *tmp = (Teacher *)LinkList_Get(list, i);
		if (tmp != NULL)
		{
			printf("age:%d ", tmp->age);
		}
	}

	while(LinkList_Length(list) > 0)
	{
		Teacher *tmp = (Teacher *)LinkList_Delete(list, 0);
		if (tmp != NULL)
		{
			printf("age:%d ", tmp->age);
		}
	}
	LinkList_Destroy(list);

	return 0;
}