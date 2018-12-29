#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

void plot_y_axis(int max_y, int max_x);
void plot_x_axis(int max_y, int max_x);
void plot(int max_y, int max_x);
int f(int x);

int main(void)
{
	int max_x, max_y;
	initscr();
	curs_set(0);
	keypad(stdscr, TRUE);
	noecho();
	cbreak();

	getmaxyx(stdscr, max_y, max_x);
	mvprintw(0, 1, "Max X --> %d", max_x);
	mvprintw(1, 1, "Max Y --> %d", max_y);
	{
		attron(A_BOLD);
		plot_y_axis(max_y, max_x);
		plot_x_axis(max_y, max_x);
		attroff(A_BOLD);
		plot(max_y, max_x);
		getch();
	}
	endwin();
	return 0;
}

void plot(int max_y, int max_x)
{
	int x = max_x / 2;
	int y = max_y / 2;
	for (int i = 0; i < x; i++) {
		mvprintw(y - f(i), x + i, "*");
	}
	for (int i = 0; i > x; i--) {
		mvprintw(y - f(i), x - i, "*");
	}
}

void plot_x_axis(int max_y, int max_x)
{
	for (int i = 0; i < max_x - 1; i++) {
		mvprintw(max_y / 2, i, "-");
		!(i % 8) ? mvprintw(max_y / 2 + 1, i, "%d", i - max_x / 2) :
			   ' ';
	}
	mvprintw(max_y / 2, max_x - 1, ">");
	mvprintw(max_y / 2 - 1, max_x - 1, "x");
}

void plot_y_axis(int max_y, int max_x)
{
	for (int j = 0; j < max_x - 1; j++) {
		mvprintw(j, max_x / 2, "|");
		!(j % 5) ? mvprintw(j, max_x / 2 + 2, "%d", max_y / 2 - j) :
			   ' ';
	}
	mvprintw(0, max_x / 2, "^");
	mvprintw(0, max_x / 2 + 2, "y");
}

int f(int x)
{
	return 10*cos(0.1*x);
}
