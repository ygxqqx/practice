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
	
	//1创建消息队列
	key=ftok(".",200);
	if(key==-1) printf("ftok err:%m\n"),exit(-1);
	
	msgid=msgget(key,0/*IPC_CREAT|IPC_EXCL|0666*/);
	if(msgid==-1)printf("get err:%m\n"),exit(-1);
	//2构造消息
		
	//3发送消息
	for(i=1;i<=10;i++)
	{
		bzero(msg.data,sizeof(msg.data));
		msg.type=1;
		sprintf(msg.data,"MessageI:%d",i);
		msgsnd(msgid,&msg,sizeof(msg.data),0);
	}
	for(i=1;i<=10;i++)
	{
		bzero(msg.data,sizeof(msg.data));
		msg.type=2;
		sprintf(msg.data,"MessageII:%d",i);
		
		msgsnd(msgid,&msg,sizeof(msg.data),0);
	}
	//4删除队列
	//msgctl(msgid,IPC_RMID,0);
}
