#include <stdio.h>
#include <signal.h>
#include <curses.h>

int main()
{
	int i;
	int c;
	WINDOW *win;

	for(i=1; i<=_NSIG; i++)
		signal(i, SIG_IGN);

	win=initscr();
	noecho();
	scrollok(win, TRUE);

	do{
		c=getch();
		printw("0x%02X (\'%c\')\n", c, c);
		refresh();
	}while(c!=0x04);

	endwin();

	puts("^D pressed so exiting");

	return 0;
}
