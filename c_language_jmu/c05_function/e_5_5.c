#include <stdio.h>
void print(int i, char ch)
{
	int j;
	for (j = 1; j <= i; j++)
		printf("%c ", ch);
	printf("\n");
}
int main()
{
	int n, i;
	char ch;
	printf("请输入行数和字母：");
	scanf("%d %c", &n, &ch);
	for (i = 1; i <= n; i++)
		print(i, ch);
	return 0;
}
