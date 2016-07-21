#pragma once
#include "socketprotocol.h"


class CMySocketImp3 :public SocketProtocol
{
public:
	CMySocketImp3(void);
	~CMySocketImp3(void);

	//�ͻ��˳�ʼ�� ��ȡhandle����
	virtual int cltSocketInit();

	//�ͻ��˷�����
	virtual int cltSocketSend( unsigned char *buf /*in*/,  int buflen /*in*/);

	//�ͻ����ձ���
	virtual int cltSocketRev( unsigned char *buf /*in*/, int *buflen /*in out*/);


	//�ͻ����ͷ���Դ
	virtual int cltSocketDestory();

private:
	char *pbuf;
	int len;

};

