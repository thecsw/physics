#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define LENGTH(s) sizeof(s) / sizeof(s[0])

/*
 * If the allocation is dynamic then
 * the values below are not used!
 */

#define ARRAY_SIZE 128
#define MAX_VALUE 48
#define DELAY 0

void print_array(int *arr, size_t size, int y, int wacky);
void update_screen(int y, int ind1, int ind2, int val1, int val2, int swaps,
		   int comps);
void randomize(int *arr, size_t size, int max_value);
void shuffle(int *arr, size_t size, int max_value);
void bubble_sort(int *arr, size_t size, int y);
void clear_x(int x, int y);

char *ch = "@";
char *space = " ";

int main(void)
{
	int max_x, max_y;
	initscr();
	curs_set(0);
	keypad(stdscr, TRUE);
	noecho();
	cbreak();

	getmaxyx(stdscr, max_y, max_x);

	int arr_size = max_x;
	{
		int *arr = (int *)malloc(sizeof(int) * arr_size);

		//randomize(arr, arr_size, max_y);
		shuffle(arr, arr_size, max_y);
		print_array(arr, arr_size, max_y, 0);
		clock_t start = clock();
		bubble_sort(arr, arr_size, max_y);
		clock_t end = clock();
		print_array(arr, arr_size, max_y, 1);
		double exec_time = ((double)(end - start) / CLOCKS_PER_SEC);
		mvprintw(4, 1, "Sorting algorithm:            Bubble Sort");
		mvprintw(5, 1, "Number of array elements:     %d", arr_size);
		mvprintw(6, 1, "Time taken to sort the array: %f", exec_time);

		free(arr);
		getch();
	}

	endwin();
	return 0;
}

void print_array(int *arr, size_t size, int y, int wacky)
{
	if (wacky) {
		attron(A_BLINK);
		attron(A_BOLD);
	}
	for (size_t i = 0; i < size; i++) {
		for (int j = 0; j < arr[i]; j++) {
			mvprintw(y - j, i, ch);
		}
	}
	attroff(A_BLINK);
	attroff(A_BOLD);
	refresh();
}

void update_screen(int y, int ind1, int ind2, int val1, int val2, int swaps,
		   int comps)
{
	usleep(100 * DELAY);

	clear_x(y, ind1);
	clear_x(y, ind2);

	mvprintw(1, 1, "Swaps: %d", swaps);
	mvprintw(2, 1, "Comparisons: %d", comps);

	for (int i = 0; i < val1; i++)
		mvprintw(y - i, ind1, ch);

	attron(A_BOLD);
	for (int i = 0; i < val2; i++)
		mvprintw(y - i, ind2, ch);
	attroff(A_BOLD);
	refresh();
}

void clear_x(int y, int x)
{
	for (int i = 0; i < y; i++)
		mvprintw(i, x, space);
}

void randomize(int *arr, size_t size, int max_value)
{
	srand(time(NULL));
	for (size_t i = 0; i < size; i++)
		arr[i] = rand() % max_value;
}

void shuffle(int *arr, size_t size, int max_value)
{
	for (size_t i = 0; i < size; i++) {
		arr[i] = max_value * i / size;
	}
	srand(time(NULL));
	for (size_t i = 0; i < size; i++) {
		int temp = arr[i];
		int j = rand() % size;
		arr[i] = arr[j];
		arr[j] = temp;
	}
}

void bubble_sort(int *arr, size_t size, int y)
{
        int swaps = 0, comps = 0;
        for (size_t i = 0; i < size - 1; i++)
		for (size_t j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swaps++;
			}
			comps++;
			update_screen(y, j, j + 1, arr[j], arr[j + 1], swaps,
				      comps);
		}
}

