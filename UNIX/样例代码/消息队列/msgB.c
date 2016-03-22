#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct msgbuf
{
	long type;
	char data[32];
};
main()
{
	key_t key;
	int msgid;
	int i;
	struct msgbuf msg;
	//1得到消息队列
	key=ftok(".",200);
	if(key==-1) printf("ftok err:%m\n"),exit(-1);
	
	msgid=msgget(key,0);
	if(msgid==-1)printf("get err:%m\n"),exit(-1);
	//2构造消息
		
	//3接收消息
	while(1)
	{
		bzero(&msg,sizeof(msg));
		msg.type=2;
		msgrcv(msgid,&msg,sizeof(msg.data),2,0);
		printf("%s\n",msg.data);
	}
	
}
