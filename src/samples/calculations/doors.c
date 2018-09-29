#include <stdio.h>

int main(void)
{
	int doors[100] = { 0 };
	printf("%d\n", doors[50]);
	for (int pass = 0; pass <= 100; pass++)
		for (int door = pass; door <= 100; door += pass + 1)
			doors[door] = !doors[door];
	for (int i = 0; i < 100; i++)
		printf("Door %d is %s\n", i + 1, (doors[i]) ? "open" : "closed");
	return 0;
}
