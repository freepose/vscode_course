#include <stdio.h>
int main()
{
	float x = 10, y;
	int *p;
	p = &x;
	y = *p;
	printf("x=%f, y=%f, *p=%d\n", x, y, *p);
	return 0;
}
