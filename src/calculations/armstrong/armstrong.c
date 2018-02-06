#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
void not(){};
int main(int argc, char** argv) {
	printf("\nArmstrong numbers.\n\n");
	clock_t begin = clock();
	unsigned long long a, b, n, i, f = 0;
	unsigned long long lim = atol(argv[1]);
	for (i = 1; i <= lim; i++) {
		n = i;
		a, b = 0;
		while(n > 0) {
			a = n % 10;
			b = b + a * a * a;
			n = n / 10;
    	}
		(b == i) ? f = 1, printf("%llu is an Armstrong number.\n", i) : not();
	}
	(f == 0) ? printf("Not Found.\n") : not();
	printf("Exiting....\n");
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nExecution time in seconds : %f\n", time_spent);
	return EXIT_SUCCESS;
}