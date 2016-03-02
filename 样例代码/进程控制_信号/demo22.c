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
	curs_set(0);//���ع��
	noecho();//��ֹ�������
	//�����Ӵ���
	w=derwin(stdscr,3,11,(LINES-3)/2,(COLS-11)/2);
	box(w,0,0);//���Ӵ���ӱ߿�
	refresh();
	wrefresh(w);
	if(fork())
	{
		//��ʾ7λ���������
		signal(SIGUSR1,handle);
		while(1){
			if(isstop==1)
			{
				pause();//pause�ᱻ�ź��ж�ֹͣ ***
			}
			num=rand()%10000000;//����7λ�����
			mvwprintw(w,1,2,"%07d",num);//��ʾ�����
			refresh();//ˢ����Ļ��
			wrefresh(w);
			usleep(10000);//��ͣ10����
		}
	}
	else
	{
		//������
		while(1)
		{
			getch();
			kill(getppid(),SIGUSR1);
		}
	}
	
	endwin();
}
