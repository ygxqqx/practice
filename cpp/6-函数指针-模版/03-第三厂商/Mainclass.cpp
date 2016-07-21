#include "iostream"
using namespace std;
#include "SocketProtocol.h"

#include "MySocket1.h"
#include "MySocketImp2.h"
#include "MySocketImp3.h"

//中石油框架（函数）
int MainOP(SocketProtocol *sp, unsigned char *buf, int buflen, unsigned char *out, int *outlen)
{
	int ret = 0;
	ret =  sp->cltSocketInit();
	ret = sp->cltSocketSend(buf, buflen);
	ret = sp->cltSocketRev(out, outlen);
	ret = sp->cltSocketDestory();
	return ret;
}
//中石油 业务层，集成第三个厂商的硬件。。接口。。。
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

//业务框架（升级成类）
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
	//在框架类中集成了一个协议。。。。
	SocketProtocol *sp;

};


//中石油 业务层，集成第三个厂商的硬件。。接口。。。
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
	mainOpClass.setSp(sp); //注入

	//在MainOPClass中包含了一个协议类sp，这种关系强
	mainOpClass.MainOP1((unsigned char *)buf, buflen, (unsigned char *)out, &outlen);

	//对sp 做函数参数。。。。
	//sp只是做函数参数，关系弱。。。
	mainOpClass.MainOP2(sp, (unsigned char *)buf, buflen, (unsigned char *)out, &outlen);

	MainOPClass::MainOP2(sp, (unsigned char *)buf, buflen, (unsigned char *)out, &outlen);
	printf("out:%s \n", out);


	delete sp;


	system("pause");
}