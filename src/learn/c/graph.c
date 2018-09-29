#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			short b = (i == 1) || (i == n) || (j == 1) ||
				  (j == n) || (i == j) || (j == n - i + 1);
			(b) ? printf("#") : printf(" ");
		}
		printf("\n");
	}
	return 0;
}
