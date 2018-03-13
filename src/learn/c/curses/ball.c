#include <ncurses.h>
#include <unistd.h>

#define DELAY 30000

int main() {
	int x = 0, y = 0;
	int max_x = 0, max_y = 0;
	int next_x = 0;
	int direction = 1;
	
	initscr();
	noecho();
	curs_set(FALSE);

	while(true) {
		getmaxyx(stdscr, max_y, max_x);
		clear();
		mvprintw(y, x, "O");
		refresh();
		usleep(DELAY);

		next_x = x + direction;
		if (next_x > max_x || next_x < 0)
			direction *= -1;
		else
			x+=direction;
	}
    endwin();
	return 0;
}
