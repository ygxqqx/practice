#include "iostream"
using namespace std;
#include "SocketProtocol.h"

#include "MySocket1.h"
#include "MySocketImp2.h"
#include "MySocketImp3.h"

//��ʯ�Ϳ�ܣ�������
int MainOP(SocketProtocol *sp, unsigned char *buf, int buflen, unsigned char *out, int *outlen)
{
	int ret = 0;
	ret =  sp->cltSocketInit();
	ret = sp->cltSocketSend(buf, buflen);
	ret = sp->cltSocketRev(out, outlen);
	ret = sp->cltSocketDestory();
	return ret;
}
//��ʯ�� ҵ��㣬���ɵ��������̵�Ӳ�������ӿڡ�����
void main2222()
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

	sp = new CMySocketImp3();

	ret = MainOP(sp,  (unsigned char *)buf, buflen, (unsigned char *)out, &outlen);
	printf("out:%s ", out);

	delete sp;


	system("pause");
}

//ҵ���ܣ��������ࣩ
class MainOPClass
{
public:
	MainOPClass()
	{
		sp = NULL;
	}
	static int MainOP2(SocketProtocol *sp, unsigned char *buf, int buflen, unsigned char *out, int *outlen)
	{
		int ret = 0;
		ret =  sp->cltSocketInit();
		ret = sp->cltSocketSend(buf, buflen);
		ret = sp->cltSocketRev(out, outlen);
		ret = sp->cltSocketDestory();
		return ret;
	}

	int MainOP1( unsigned char *buf, int buflen, unsigned char *out, int *outlen)
	{
		int ret = 0;

		ret =  sp->cltSocketInit();
		ret = sp->cltSocketSend(buf, buflen);
		ret = sp->cltSocketRev(out, outlen);
		ret = sp->cltSocketDestory();
		return ret;
	}
public:
	SocketProtocol * getSp() const 
	{ 
		return sp;
	}
	void setSp(SocketProtocol * val) 
	{ 
		sp = val; 
	}
protected:
private:
	//�ڿ�����м�����һ��Э�顣������
	SocketProtocol *sp;

};


//��ʯ�� ҵ��㣬���ɵ��������̵�Ӳ�������ӿڡ�����
void main()
{
	int ret = 0;
	char buf[1024] = {0};
	int buflen = 10;

	char out[1024] = {0};
	int outlen = 10;
	 SocketProtocol *sp = NULL;
	 strcpy(buf, "dddddddddddddssssssssssssssssss");

	sp = new CMySocketImp3();

	MainOPClass mainOpClass;
	mainOpClass.setSp(sp); //ע��

	//��MainOPClass�а�����һ��Э����sp�����ֹ�ϵǿ
	mainOpClass.MainOP1((unsigned char *)buf, buflen, (unsigned char *)out, &outlen);

	//��sp ������������������
	//spֻ����������������ϵ��������
	mainOpClass.MainOP2(sp, (unsigned char *)buf, buflen, (unsigned char *)out, &outlen);

	MainOPClass::MainOP2(sp, (unsigned char *)buf, buflen, (unsigned char *)out, &outlen);
	printf("out:%s \n", out);


	delete sp;


	system("pause");
}