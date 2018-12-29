#include <stdio.h>
#include <ncurses.h>

int X_RES, Y_RES;

int main()
{
	char *box = "█";

	initscr();
	curs_set(0);
	keypad(stdscr, TRUE);
	noecho();
	cbreak();

	getmaxyx(stdscr, Y_RES, X_RES);
	getch();

	
	return 0;
}
