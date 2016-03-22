#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <curses.h>
#include <signal.h>
WINDOW*winfo,*wmsg;
int fd;
int r;
struct sockaddr_in dr;
int isover=1;

int initSocket();
void initUI(); 
void destroy();
void handle(int s)
{
	int status;
	wait(&status);
	destroy();
	exit(-1);	
}
main()
{	
	//printf("网络初始化成功!\n");
	initUI();
	r=initSocket();	
	if(r==-1) exit(-1);
	signal(SIGCHLD,handle);
	if(fork())
	{
		//输入，发送
		char buf[256];
		while(1)
		{
			mvwgetstr(wmsg,1,1,buf);
			//buf[r]=0;
			send(fd,buf,strlen(buf),0);			
			//wclear(wmsg);
			//box(wmsg,0,0);
			refresh();
			wrefresh(wmsg);
			wrefresh(winfo);
		}
	}
	else
	{
		
		//接收，显示
		char buf[256];
		int line=1;
		while(1)
		{			
			r=recv(fd,buf,255,0);
			if(r==-1) break;
			if(r==0) break;
			buf[r]=0;
			mvwaddstr(winfo,line,1,buf);
			line++;			
			if(line>=(LINES-3))
			{
				wclear(winfo);
				line=1;
				box(winfo,0,0);				
			}
			
			
			wmove(wmsg,1,1);
			touchwin(wmsg);
			refresh();
			wrefresh(winfo);			
			wrefresh(wmsg);
		}
		exit(-1);
	}
		
	destroy();
}
void destroy()
{
	close(fd);
	endwin();
}
void initUI()
{
	initscr();
	winfo=derwin(stdscr,(LINES-3),COLS,0,0);
	wmsg=derwin(stdscr,3,COLS,LINES-3,0);
	keypad(stdscr,TRUE);
	keypad(wmsg,TRUE);
	keypad(winfo,TRUE);
	box(winfo,0,0);
	box(wmsg,0,0);
	refresh();
	wrefresh(winfo);
	wrefresh(wmsg);
}
int initSocket()
{
	fd=socket(AF_INET,SOCK_STREAM,0);
	if(fd==-1) return -1;
		
	dr.sin_family=AF_INET;
	dr.sin_port=htons(9989);
	dr.sin_addr.s_addr=inet_addr("192.168.180.92");
	r=connect(fd,(struct sockaddr*)&dr,sizeof(dr));
	if(r==-1)
	{
		close(fd);
		return -1;
	}
	return 0;
}
