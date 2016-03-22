#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/*3 ��������
typedef struct _LinkList
{
	int data;
	struct _LinkList*next;
} LinkList;
�����½��������  1 2 3 4 5 6 7 8 12 19 ��������
1����������
2��ɾ�����ֵΪż���Ľ��
3����д��������
*/

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef struct Node
{
	int data;
	struct Node *next;
}SLIST;



//��д����SList_Creat����������ͷ���ĵ�������ѭ��������㣬
//����������е���ֵ�Ӽ������룬��-1��Ϊ���������־�������ͷ����ַ�ɺ���ֵ���ء�

SLIST *SList_Creat();
int SList_Print(SLIST *pHead);
int SList_NodeInsert(SLIST *pHead, int x, int y);
int SList_NodeDel(SLIST *pHead, int x);
int SList_Destory(SLIST *pHead);
int SList_Resve(SLIST *pHead);

//��д���Ƚ��ġ���������Ĺ�������  1�깤��������
SLIST *SList_Creat()
{
	SLIST *pHead = NULL, *pM =NULL, *pCur = NULL;
	int data = 0;
	//1 ����ͷ��㲢��ʼ��
	pHead = (SLIST *)malloc(sizeof(SLIST));
	if (pHead == NULL)
	{
		return NULL;
	}
	pHead->data = 0;
	pHead->next = NULL;

	//2 �Ӽ����������ݣ�����ҵ����
	printf("\nplease enter the data of node(-1:quit) ");
	scanf("%d", &data);

	//3 ѭ������
	//��ʼ����ǰ�ڵ㣬ָ��ͷ���
	pCur = pHead;
	while(data != -1)
	{
		//�½�ҵ���� ����ʼ��
		//1 ���ϵ�malloc �µ�ҵ��ڵ� ===PM
		pM = (SLIST *)malloc(sizeof(SLIST));
		if (pM == NULL)
		{
			SList_Destory(pHead); //
			return NULL;
		}
		pM->data = data;
		pM->next = NULL;

		//2����pM�ڵ�������
		pCur->next = pM;

		//3 pM�ڵ��ɵ�ǰ�ڵ�
		pCur = pM; //pCur = pCur->next;


		//2 �Ӽ����������ݣ�����ҵ����
		printf("\nplease enter the data of node(-1:quit) ");
		scanf("%d", &data);
	}

	return pHead;
}

// 2�깤��������
int SList_Creat2(SLIST **mypHead)
{
	int ret = 0;
	SLIST *pHead = NULL, *pM =NULL, *pCur = NULL;
	int data = 0;
	//1 ����ͷ��㲢��ʼ��
	pHead = (SLIST *)malloc(sizeof(SLIST));
	if (pHead == NULL)
	{
		ret = -1;
		printf("func SList_Creat2() err:%d ", ret);
		return ret;
	}
	pHead->data = 0;
	pHead->next = NULL;

	//2 �Ӽ����������ݣ�����ҵ����
	printf("\nplease enter the data of node(-1:quit) ");
	scanf("%d", &data);

	//3 ѭ������
	//��ʼ����ǰ�ڵ㣬ָ��ͷ���
	pCur = pHead;
	while(data != -1)
	{
		//�½�ҵ���� ����ʼ��
		//1 ���ϵ�malloc �µ�ҵ��ڵ� ===PM
		pM = (SLIST *)malloc(sizeof(SLIST));
		if (pM == NULL)
		{
			SList_Destory(pHead); //
			ret = -2;
			printf("func SList_Creat2() err:%d ", ret);
			return ret;
		}
		pM->data = data;
		pM->next = NULL;

		//2����pM�ڵ�������
		pCur->next = pM;

		//3 pM�ڵ��ɵ�ǰ�ڵ�
		pCur = pM; //pCur = pCur->next;

		//2 �Ӽ����������ݣ�����ҵ����
		printf("\nplease enter the data of node(-1:quit) ");
		scanf("%d", &data);
	}

	*mypHead = pHead;
	return ret;
}

int SList_Print(SLIST *pHead)
{
	SLIST *p = NULL;

	if (pHead == NULL)
	{
		return -1;
	}
	p = pHead->next;
	printf("\nBegin ");
	while(p)
	{
		printf("%d ", p->data);
		p  = p->next;
	}
	printf(" End");
	return 0;
}

int SList_Destory(SLIST *pHead)
{

	SLIST *p = NULL, *tmp = NULL;
	if (pHead == NULL)
	{
		return -1;
	}
	p = pHead;
	while(p)
	{
		//������һ�����λ��
		tmp = p->next;
		free(p);//ɾ����ǰ�ڵ�
		p = tmp; //�ڵ�ָ�����
	}
	return 0;
}

//���ܣ���ֵΪx�Ľ��ǰ������ֵΪy�Ľ�㣻��ֵΪx�Ľ�㲻���ڣ�����ڱ�β��
int SList_NodeInsert(SLIST *pHead, int x, int y)
{
	SLIST *pCur = NULL, *pPre = NULL, *pM = NULL;

	//����y��ֵmalloc�½��
	pM = (SLIST *)malloc(sizeof(SLIST));
	if (pM == NULL)
	{
		return -1;
	}
	pM->data = y;
	pM->next = NULL;

	//׼��pCur Pre����
	pPre = pHead;
	pCur = pHead->next;

	while (pCur)
	{
		if (pCur->data == x)
		{
			//�������
			break;
		}

		pPre = pCur; //��ǰ��������
		pCur = pCur->next; //�õ�ǰ������
	}

	//1 pM������Ӻ������
	//pM->next = pCur;
	pM->next = pPre->next;
	//2 ��ǰ���������pM 
	pPre->next = pM; 

	return 0;
}

int SList_NodeDel(SLIST *pHead, int x)
{
	SLIST *pCur = NULL, *pPre = NULL;

	//׼��pCur Pre����
	pPre = pHead;
	pCur = pHead->next;

	while (pCur)
	{
		if (pCur->data == x)
		{
			//�������
			break;
		}

		pPre = pCur; //��ǰ��������
		pCur = pCur->next; //�õ�ǰ������
	}

	if (pCur == NULL)
	{
		printf("û���ҵ�Ҫɾ���Ľ��\n");
		return -1;
	}
	//��������ɾ�����
	pPre->next =   pCur->next;
	//�ͷ��ڴ�
	free(pCur);
	return 0;
}

//ɾ���ڵ�ֵΪż����
int SList_NodeSpecialDel(SLIST *pHead)
{
	SLIST *pCur = NULL, *pPre = NULL;

	//׼��pCur Pre����
	pPre = pHead;
	pCur = pHead->next;

	while (pCur)
	{
		if (pCur->data %2 == 0)
		{
			//�������
			break;
		}

		pPre = pCur; //��ǰ��������
		pCur = pCur->next; //�õ�ǰ������
	}

	if (pCur == NULL)
	{
		printf("û���ҵ�Ҫɾ���Ľ��\n");
		return 0;
	}
	//��������ɾ�����
	pPre->next =   pCur->next;
	//�ͷ��ڴ�
	free(pCur);
	return 0;
}


int SList_NodeDelOueve(SLIST *pHead)
{
	SLIST *p = NULL;
	if (pHead == NULL)
	{
		return -1;
	}
	p = pHead->next;
	while (p)
	{
		 SList_NodeSpecialDel(p);
		p = p->next;
	}
	return 0;
}


int SList_Resve(SLIST *pHead)
{
	SLIST *t = NULL, *p = NULL, *q = NULL;

	if (pHead == NULL)
	{
		return -1;
	}
	if (pHead->next == NULL || pHead->next->next == NULL)
	{
		return -2;
	}

	//��ʼ�����û���
	p = pHead->next;
	q = pHead->next->next;

	while (q != NULL)
	{
		//����֮ǰ��q�ĺ�̽�㱣��
		t = q->next;
		//���ò���
		q->next = p;

		//3��ǰ���ڵ����  //3 4�Ǵ�����һ��whileѭ�����õĻ���
		p = q;

		//4�����ýڵ����
		q = t;
	}

	//��������Ժ�pָ�����һ����㡣qָ��null
	pHead->next->next = NULL; //
	pHead->next = p;

	return 0;
}

void main()
{
	int ret = 0;
	SLIST *pHead = NULL;
	pHead = 	SList_Creat();
	ret = SList_Print(pHead);
	if (ret != 0)
	{
		printf("func SList_Print() err:%d\n", ret);
		return ;
	}

	//ɾ�����ֵΪż���Ľ��
	ret = SList_NodeDelOueve(pHead);
	if (ret != 0)
	{
		printf("func SList_NodeDelOueve(pHead)() err:%d\n", ret);
		return ;
	}
	ret = SList_Print(pHead);
	if (ret != 0)
	{
		printf("func SList_Print() err:%d\n", ret);
		return ;
	}


	ret = SList_Destory(pHead);
	if (ret != 0)
	{
		printf("func SList_Destory() err:%d\n", ret);
		return ;
	}

	system("pause");
}