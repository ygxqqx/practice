
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct Node {
	int		data;
	struct Node *next;
}SLIST;

SLIST	*SList_Creat();
int		SList_Print(SLIST *pHead);
int		SList_NodeInsert(SLIST *pHead, int x , int y);
int		SList_NodeDel(SLIST *pHead, int y);
int		SList_Destory(SLIST *pHead);

int		SList_Destory(SLIST *pHead)
{
	int		rv = 0;
	SLIST	*p = NULL, *pTmp = NULL;
	
	if (pHead == NULL)
	{
		rv = -1;
		printf("func SList_Destory() err:%d", rv);
		return rv;
	}
	//ѭ����������
	p = pHead;
	while (p)
	{
		//����������
		pTmp = p->next;
		//ɾ����ǰ���
		free(p);
		//��ǰ���ָ�����
		p = pTmp;
	}

	return rv;
}

//��̬��������ͷ�������
//ѭ�������û����룬malloc�½�㣬�½��������
//�����е��
//1 ҵ���߼����ڴ�й¶����
//2 ����ֵΪ�����׵�ַռ���˴�����
SLIST *SList_Creat()
{
	//int	rv = 0;
	int		data = 0;
	SLIST *pHead = NULL, *pCur = NULL, *pM = NULL;

	//����ͷ��㲢��ʼ��
	pHead = (SLIST *)malloc(sizeof(SLIST));
	if (pHead == NULL)
	{
		return NULL;
	}
	pHead->data = 0;
	pHead->next = NULL;

	//�ȴ��û�����
	printf("\nplease enter the data of node:(-1:quit) ");
	scanf("%d", &data);

	//ѭ���ж��û�����
	pCur = pHead;
	while (data != -1)
	{
		//�����½�㲢��ֵ
		pM = (SLIST *)malloc(sizeof(SLIST));
		if (pM == NULL)
		{
			return NULL;
		}
		pM->data = data;
		pM->next = NULL;

		//�½��������
		pCur->next = pM;
		
		//��ǰָ���������һ����λ
		pCur = pM;

		//�ȴ��û�����
		printf("\nplease enter the data of node:(-1:quit) ");
		scanf("%d", &data);
	}

	return pHead;
}

//������������1:1��
//���к������ڴ��malloc��Դ����ʱ�������ṹҪ��  
//һ�����һ������
//��׮˼�����Ӧ�ã����п�������߿����ٶ�
//Ұָ�룺ָ�������ָ���ڴ�ռ����ͷţ�����ָ��û�ó�NULL����Ժ����������Ӱ�� 
//����׳������ ʵս����
SLIST *SList_Creat2()
{
	int		rv = 0;
	int		data = 0;
	SLIST *pHead = NULL, *pCur = NULL, *pM = NULL;

	//����ͷ��㲢��ʼ��
	pHead = (SLIST *)malloc(sizeof(SLIST));
	if (pHead == NULL)
	{
		rv = -1;
		printf("func SList_Creat2() err:%d", rv);
		goto End;
	}
	pHead->data = 0;
	pHead->next = NULL;

	//�ȴ��û�����
	printf("\nplease enter the data of node:(-1:quit) ");
	scanf("%d", &data);

	//ѭ���ж��û�����
	pCur = pHead;
	while (data != -1)
	{
		//�����½�㲢��ֵ
		pM = (SLIST *)malloc(sizeof(SLIST));
		if (pM == NULL)
		{
			rv = -2;
			printf("func SList_Creat2() err:%d", rv);
			goto End;
		}
		pM->data = data;
		pM->next = NULL;

		//�½��������
		pCur->next = pM;

		//��ǰָ���������һ����λ
		pCur = pM;

		//�ȴ��û�����
		printf("\nplease enter the data of node:(-1:quit) ");
		scanf("%d", &data);
	}

End:
	
	if (rv != 0)
	{
		SList_Destory(pHead); //Ұָ��
		pHead = NULL;
	}
	return pHead;
}

//������������ 2��  ����ֵΪ�����׵�ַռ���˴�����
/*
	func1����func2��func2�з����ڴ�malloc�����ݸ�fun1�ķ��������� 
	1 return ����
	2 ����ָ������������

	//����ָ������÷���
	//���롡char *argv[];
	//���: ʵ��ȡ��ַ����ֵ���βΣ��ڱ����ú������棬ͨ��*�βΣ�*p�� = 
	//ָ�������������ľ���
*/
//��ȷ���нӿڿ�ķ�װ�����  2�깤������
int SList_Creat3(SLIST **headnode)
{
	int		rv = 0;
	int		data = 0;
	SLIST *pHead = NULL, *pCur = NULL, *pM = NULL;

	//����ͷ��㲢��ʼ��
	pHead = (SLIST *)malloc(sizeof(SLIST));
	if (pHead == NULL)
	{
		rv = -1;
		printf("func SList_Creat2() err:%d", rv);
		goto End;
	}
	pHead->data = 0;
	pHead->next = NULL;

	//�ȴ��û�����
	printf("\nplease enter the data of node:(-1:quit) ");
	scanf("%d", &data);

	//ѭ���ж��û�����
	pCur = pHead;
	while (data != -1)
	{
		//�����½�㲢��ֵ
		pM = (SLIST *)malloc(sizeof(SLIST));
		if (pM == NULL)
		{
			rv = -2;
			printf("func SList_Creat2() err:%d", rv);
			goto End;
		}
		pM->data = data;
		pM->next = NULL;

		//�½��������
		pCur->next = pM;

		//��ǰָ���������һ����λ
		pCur = pM;

		//�ȴ��û�����
		printf("\nplease enter the data of node:(-1:quit) ");
		scanf("%d", &data);
	}

End:

	if (rv != 0)
	{
		SList_Destory(pHead); //Ұָ��
		pHead = NULL;
	}
	//����2��*p��Ӹ�ֵ��ָ����ڵ��������
	//*p �ڵȺŵ���� �޸���ָ�ڴ������ֵ����ֵ��
	//*p �ڵȺŵ��ұߣ�ȡֵ
	//��� *p2++ = *p1++ //
	*headnode = pHead;
	return rv;
}

//�������飺3��
//��ҵ���Ƹ��� ͨ������ӿڿ��������
//����Ŀ��
//˼�룺
int SList_Creat4(void **headnode)
{
	return 0;
}

//���ɶ�: *p��Ӹ�ֵ��ָ����ڵ��������
/*
//������������ 
	1)����һ��ʵ�� ��2)����һ���β�
		int rv = 0;		int *p = NULL; p = &rv  *p
		void *p = NULL;	void **p2		p2 = &p1; *p2 = 0x1 
	3)ʵ�ε�ַ�����βΣ�*�βΣ�ȥ�޸�ʵ�ε�ֵ
*/

void Test01()
{
	int rv = 0;

	int *p = 0x1;
	rv = 1; //ֱ�Ӹ�ֵ

	p = &rv;
	*p = 2; //��Ӹ�ֵ  //*p �ڵȺŵ���� �޸���ָ�ڴ������ֵ����ֵ��
	printf("%d", rv); //
}

void Test02()
{
	void *p1 = NULL;
	void **p2 = NULL;
	p1 = 0x1; //ֱ�Ӹ�ֵ
	
	p2 = &p1;
	
	*p2 = 0x2; //��Ӹ�ֵ ȥ�޸�p1��ֵ ��0x1==>0x2
	
	printf("%x", p1); //*p��Ӹ�ֵ
}


int		SList_Print(SLIST *pHead)
{
	int		rv = 0;
	SLIST	*p = NULL;

	if (pHead == NULL)
	{
		rv = -1;
		printf("func SList_Print() err:%d", rv);
		return rv;
	}
	p = pHead->next;
	printf("\nBegin ");
	while(p)
	{
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("End\n");

	return rv;
}

int		SList_NodeInsert(SLIST *pHead, int x , int y)
{
	int		rv = 0;
	SLIST	*pM = NULL, *pCur = NULL, *pPre = NULL;

	if (pHead == NULL)
	{
		rv = -1;
		printf("func SList_NodeInsert() err.\n", rv);
		return rv;
	}

	//malloc�½�㲢��ֵ
	pM = (SLIST *)malloc(sizeof(SLIST));
	if (pM == NULL)
	{
		rv = -2;
		printf("func SList_NodeInsert() err.\n", rv);
		return rv;
	}
	pM->data = y;
	pM->next = NULL;

	//��ʼ��ǰ����㡢��ǰ���ָ�����
	pPre = pHead;
	pCur = pHead->next;

	//�����������ҷ��������Ľ��
	//�ҳ�pre���͵�ǰ���
	while(pCur)
	{
		if (pCur->data == x)
		{
			break;
		}
		//ǰ�������ƣ���ǰ�ڵ����
		pPre = pCur;
		pCur = pCur->next;
	}
	
	//�ڵ�ǰ���֮ǰ�����½ڵ�
	//�½�����ӵ�ǰ���
	pM->next = pPre->next;
	//ǰ����������½�㣬����½��������
	pPre->next = pM;

	return rv;
}


int		SList_NodeDel(SLIST *pHead, int y)
{
	int		rv = 0;
	SLIST	*pCur = NULL, *pPre = NULL;

	if (pHead == NULL)
	{
		rv = -1;
		printf("func SList_NodeInsert() err.\n", rv);
		return rv;
	}

	//��ʼ��ǰ����㡢��ǰ���ָ�����
	pPre = pHead;
	pCur = pHead->next;

	//�����������ҷ��������Ľ��
	//�ҳ�pre���͵�ǰ���
	while(pCur)
	{
		if (pCur->data == y)
		{
			break;
		}
		//ǰ�������ƣ���ǰ�ڵ����
		pPre = pCur;
		pCur = pCur->next;
	}

	//û�з��������Ľ�㣬����
	if (pCur == NULL)
	{
		rv = -2;
		printf("func SList_NodeDel() err:%d", rv);
		return rv;
	}
	//ɾ�����
	//ǰ��������Ӻ������
	pPre->next = pCur->next;
	free(pCur);
	
	return rv;
}

int main()
{
	int		rv = 0;
	SLIST	*pHead = NULL;

	Test();
	/*
	pHead = SList_Creat2();
	if (pHead == NULL)
	{
		printf("func SList_Creat2() err\n");
		return rv;
	}
	printf("func SList_Creat() ok\n");
	*/

	rv = SList_Creat3(&pHead);
	if (rv != 0)
	{
		printf("func SList_Creat3() err:%d\n", rv);
		goto End;
	}
	printf("func SList_Creat3() ok\n");

	rv = SList_Print(pHead);
	if (rv != 0)
	{
		printf("func SList_Print() err:%d\n", rv);
		goto End;
	}
	printf("func SList_Print() ok\n");

	rv = SList_NodeInsert(pHead, 20, 19);
	if (rv != 0)
	{
		printf("func SList_NodeInsert() err:%d\n", rv);
		goto End;
	}
	rv = SList_Print(pHead);
	if (rv != 0)
	{
		printf("func SList_Print() err:%d\n", rv);
		goto End;
	}

	rv = SList_NodeDel(pHead,19);
	if (rv != 0)
	{
		printf("func SList_NodeDel() err:%d\n", rv);
		goto End;
	}
	rv = SList_Print(pHead);
	if (rv != 0)
	{
		printf("func SList_Print() err:%d\n", rv);
		goto End;
	}

End:
	rv = SList_Destory(pHead);
	if (rv != 0)
	{
		printf("func SList_Destory() err:%d\n", rv);
		goto End;
	}
	printf("func SList_Destory() ok\n");

	getchar();
	getchar();
	return 0;
}