#include "MySocketImp3.h"


CMySocketImp3::CMySocketImp3(void)
{
	pbuf = NULL;
	len = 0;
}

CMySocketImp3::~CMySocketImp3(void)
{
	printf("ddddd");
}


//�ͻ��˳�ʼ�� ��ȡhandle����
int CMySocketImp3::cltSocketInit()
{
	pbuf = NULL;
	len = 0;
	return 0;
}

//�ͻ��˷�����
int CMySocketImp3::cltSocketSend( unsigned char *buf /*in*/,  int buflen /*in*/)
{
	if (buf == NULL || buflen<0 )
	{
		return -1;
	}
	this->pbuf = (char *)malloc(buflen *sizeof(char ));
	if (this->pbuf == NULL)
	{
		return -2;
	}
	memcpy(this->pbuf, buf, buflen);
	this->len = buflen;
	return 0;
}
//�ͻ����ձ���
int CMySocketImp3::cltSocketRev( unsigned char *buf /*in*/, int *buflen /*in out*/)
{
	if (buf == NULL ||buflen== NULL)
	{
		return -1;
	}
	memcpy(buf, this->pbuf, this->len);
	*buflen = this->len;
	return 0;
}

//�ͻ����ͷ���Դ
int CMySocketImp3::cltSocketDestory()
{
	if (this->pbuf != NULL)
	{
		free(this->pbuf);
		this->pbuf= NULL;
		this->len = 0;
	}
	return 0;
}