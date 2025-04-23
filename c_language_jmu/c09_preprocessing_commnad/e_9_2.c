#include <stdio.h>
#define s(a, b, c, d) \
	b = a * a;        \
	c = a * a * a;    \
	d = a * a * a * a
int main()
{
	float a, b, c, d;
	scanf("%f", &a);
	s(a, b, c, d);
	printf("a=%.2f,b=%.2f,c=%.2f,d=%.2f\n", a, b, c, d);
	return 0;
}
