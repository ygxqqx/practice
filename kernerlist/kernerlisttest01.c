#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "malloc.h"
#include "list.h"

/*
Linux�ں�Ϊ�����ṩ��һ�µķ��ʽӿڡ�
void INIT_LIST_HEAD(struct list_head *list)��
void list_add(struct list_head *new, struct list_head *head)��
void list_add_tail(struct list_head *new, struct list_head *head)��
void list_del(struct list_head *entry);
int list_empty(const struct list_head *head)��
*/

struct teacher_node {
	int		id;
	char	name;
	int		age;
	struct list_head list;
};

//ջ�Ͼ�̬���� ��ѧϰ�﷨
int main_stack()
{
	//����ṹ
	struct list_head head, *plist;
	
	//ҵ�����ݽṹ�����а�������ṹ��
	struct teacher_node a, b;
	
	a.id = 2;
	b.id = 3;
	
	INIT_LIST_HEAD(&head);
	list_add(&a.list, &head);
	list_add(&b.list, &head);
	
	list_for_each(plist, &head) {
		struct teacher_node *node = list_entry(plist, struct teacher_node, list);
		printf("id = %d\n", node->id);
	}
	
	return 0;
}

//��̬����
struct list_head * main_creat()
{
	//����ͷ��㼰����ָ��
	struct list_head *pHead = NULL, *pCur = NULL;

	//ҵ�����ݽṹ
	struct teacher_node  *pA = NULL, *pB = NULL;

	//��������ͷ���
	pHead =  (struct list_head *)malloc(sizeof(struct list_head));

	pA =  (struct teacher_node *)malloc(sizeof(struct teacher_node));
	pB =  (struct teacher_node *)malloc(sizeof(struct teacher_node));
	
	memset(pHead, 0, sizeof(struct list_head));

	memset(pA, 0, sizeof(struct teacher_node));
	memset(pB, 0, sizeof(struct teacher_node));

	pA->id = 20;
	pB->id = 30;

	//��ʼ��ͷ����
	INIT_LIST_HEAD(pHead);

	//��ӽ��
	list_add(&pA->list, pHead);
	list_add(&pB->list, pHead);

	//��������
	list_for_each(pCur, pHead) {
		struct teacher_node *node = list_entry(pCur, struct teacher_node, list);
		printf("id = %d\n", node->id);
	}	
	return pHead;
}

int mainxx()
{
	struct list_head * head = NULL, *pCur = NULL;
	
	head = main_creat();
	if (head == NULL)
	{
		printf("func main_creat() err\n");
		return -1;
	}

	//��������
	list_for_each(pCur, head) {
		struct teacher_node *node = list_entry(pCur, struct teacher_node, list);
		printf("id = %d\n", node->id);
	}
	getchar();
	getchar();
	return 0;
}

int main()
{	
	main_stack();
		
	getchar();
	getchar();
	return 0;
}