
// Example 1-1: input two positive integers, and output the larger one

#include <stdio.h>

int main()
{
	int first, second;

	scanf("%d %d", &first, &second);
	if (first > second)
	{
		printf("larger value is %d\n", first);
	}
	else
	{
		printf("larger value is %d\n", second);
	}
	return 0;
}

//