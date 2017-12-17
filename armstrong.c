#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char** argv) {
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
    	if (b == i) {
			f = 1;
			printf("%llu is an Armstrong number.\n", i);
		}
	}
	if (f == 0) printf("Not Found.\n");
	printf("Exiting....\n");
	return EXIT_SUCCESS;
}
