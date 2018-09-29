#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int static_foo()
{
	static int counter = 0;
	counter++;
	printf("%d ", counter);
}

int foo()
{
	int abc = 0;
        abc++;
	printf("%d ", abc);
}

float rsqrt(float number) {
	long i;
	float y;
	y = number;
	i = * ( long * ) &y;
	i = 0x5f3759df - (i >> 1);
	y = * ( float * ) &i;
	return y;
}

int main(void)
{
/*	static_foo();
	static_foo();

	printf("\n");
	
	foo();
	foo();
*/		
	/*while (1) {
		float x;
		printf("x = ");
		scanf("%f", &x);
		int y = *(int*)&x;
		printf("y = %d\n\n", y);
	}
	*/

	int trials = 10000000;

	clock_t begin = clock();
	for (int i = 0; i < trials; i ++) {
		float x = rand();
		float y = rsqrt(x);
		//printf("%f", y);
	}
	clock_t end = clock();
	double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
	printf("FAST TIME -> %f\n\n", time_spent);
	double first = time_spent;
	
	begin = clock();
	for (int i = 0; i < trials; i ++) {
		float x = rand();
		float y = (float)(1 / sqrt(x));	
	}
	end = clock();
	time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
	printf("TIME -> %f\n\n", time_spent);

	double ration = 100 * ((time_spent - first) / time_spent);
	
	printf("Is faster : %f\%\n\n", ration);
	
}
