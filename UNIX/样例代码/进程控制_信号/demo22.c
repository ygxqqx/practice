#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <math.h>
#include <curses.h>
WINDOW *w;
int num;
int isstop=0;
void handle(int s)
{
	if(s==SIGUSR1)
	{
		if(isstop==1)
			isstop=0;
		else
			isstop=1;
	}
}

main()
{
	initscr();
	curs_set(0);//隐藏光标
	noecho();//禁止输入回显
	//创建子窗体
	w=derwin(stdscr,3,11,(LINES-3)/2,(COLS-11)/2);
	box(w,0,0);//给子窗体加边框
	refresh();
	wrefresh(w);
	if(fork())
	{
		//显示7位数的随机数
		signal(SIGUSR1,handle);
		while(1){
			if(isstop==1)
			{
				pause();//pause会被信号中断停止 ***
			}
			num=rand()%10000000;//产生7位随机数
			mvwprintw(w,1,2,"%07d",num);//显示随机数
			refresh();//刷新屏幕。
			wrefresh(w);
			usleep(10000);//暂停10毫秒
		}
	}
	else
	{
		//处理按键
		while(1)
		{
			getch();
			kill(getppid(),SIGUSR1);
		}
	}
	
	endwin();
}
