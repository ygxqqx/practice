#include "iostream"
using namespace std;
#include "SocketProtocol.h"

#include "MySocket1.h"

//��ʯ�Ϳ��
int MainOP(SocketProtocol *sp, unsigned char *buf, int buflen, unsigned char *out, int *outlen)
{
	int ret = 0;
	ret =  sp->cltSocketInit();
	ret = sp->cltSocketSend(buf, buflen);
	ret = sp->cltSocketRev(out, outlen);
	ret = sp->cltSocketDestory();
	return ret;
}

//ҵ��㣬���ɵ��������̵�Ӳ�������ӿڡ�����
void main()
{
	int ret = 0;
	char buf[1024] = {0};
	int buflen = 10;

	char out[1024] = {0};
	int outlen = 10;
	 SocketProtocol *sp = NULL;
	 strcpy(buf, "dddddddddddddssssssssssssssssss");
	 /*
	ret =  sp->cltSocketInit();
	ret = sp->cltSocketSend((unsigned char *)buf, buflen);
	ret = sp->cltSocketRev((unsigned char *)out, &outlen);
	ret = sp->cltSocketDestory();
	*/

	sp = new CMySocketImp();

	ret = MainOP(sp,  (unsigned char *)buf, buflen, (unsigned char *)out, &outlen);
	printf("out:%s ", out);

	delete sp;

	system("pause");
}