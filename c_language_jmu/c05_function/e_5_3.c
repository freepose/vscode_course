#include <stdio.h>
#include <conio.h>
int main()
{
	void pyramid();
	pyramid();
	return 0;
}
void pyramid()
{
	int i, j;
	char c = 'A';
	for (i = 1; i <= 5; i++)
	{
		for (j = 1; j <= 5 - i; j++)
			printf(" ");
		for (j = 1; j <= i * 2 - 1; j++)
			printf("%c", c);
		printf("\n");
		c++;
	}
	c--;
	for (i = 4; i >= 1; i--)
	{
		c--;
		for (j = 1; j <= 5 - i; j++)
			printf(" ");
		for (j = 1; j <= 2 * i - 1; j++)
			printf("%c", c);
		printf("\n");
	}
}
