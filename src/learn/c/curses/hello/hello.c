#include <ncurses.h>
#include <unistd.h>

int main() {
	initscr();
//	raw();
	//noecho();
	//curs_set(FALSE);
//	printw("Hello World!");
	for (int i = 0; i < 10; i++) {
		mvprintw(i, i, "Hello, World!");
	}
	printw("Hello there!");
//	mvprintw(0, 2, "Hello, World!");
	refresh();
        getch();
	endwin();
	return 0;
}
