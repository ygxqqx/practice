#pragma once
#include "socketprotocol.h"


class CMySocketImp2 :public SocketProtocol
{
public:
	CMySocketImp2(void);
	~CMySocketImp2(void);

	//客户端初始化 获取handle上下
	virtual int cltSocketInit();

	//客户端发报文
	virtual int cltSocketSend( unsigned char *buf /*in*/,  int buflen /*in*/);

	//客户端收报文
	virtual int cltSocketRev( unsigned char *buf /*in*/, int *buflen /*in out*/);


	//客户端释放资源
	virtual int cltSocketDestory();

private:
	char *pbuf;
	int len;

};

