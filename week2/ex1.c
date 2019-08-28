#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
	int a;
	float b;
	double c;
	
	a = INT_MAX;
	b = FLT_MAX;
	c = DBL_MAX;
	printf("maximum integer value = %d\n", a);
	printf("size of max integer = %d\n", sizeof(a));
	printf("maximum float value = %.10e\n", b);
	printf("size of max float = %d\n", sizeof(b));
	printf("maximum double value = %.10e\n", c);
	printf("size of max double = %d\n", sizeof(c));
	return 0;
}