#include <ncurses.h>

int main(void)
{
	initscr();
	noecho();
	//wprintw(win, "Hi there!");
	
	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 80; j++)
			mvprintw(i, j, "%c", 74);
	refresh();
	
	
	getch();
	endwin();
	return 0;
}
