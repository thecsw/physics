#include <stdio.h>

int add(int x, int y) {
	int keep = (x & y) << 1;
	int res = x^y;
	
	if (keep == 0)
		return res;
	
	add(keep, res);
}

int main(){
	int a, b;
	while(1) {
		scanf("%d %d", &a, &b);
		printf("%d\n", add(a, b));
	}
	return 0;
}
