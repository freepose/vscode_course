#include <stdio.h>
int main()
{
	int a[3][4] = {{0, 1, 2, 3}, {10, 11, 12, 13}, {20, 21, 22, 23}};
	int *p, i, j;
	p = a;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
			printf("%4d", *(*(a + i) + j));
		printf("\n");
	}
	return 0;
}
