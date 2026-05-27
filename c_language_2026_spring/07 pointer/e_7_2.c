
// Example 7-1

#include <stdio.h>

int main()
{
	int x;
	int y;
	int* p = 0;

	scanf("%d", &x);

	p = &x;
	y = *p;

	printf("x=%d, y=%d\n", x, y);

	return 0;
}
