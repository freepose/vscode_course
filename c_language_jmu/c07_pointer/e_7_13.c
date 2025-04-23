#include <stdio.h>
#include <string.h>
int main()
{
	char forwardRead[10000];
	char *palindromicPoem = forwardRead;
	int palindromic(char *palindromicPoem);
	printf("请在一行内输入诗句，标点符号用空格代替：\n");
	gets(palindromicPoem);
	if (palindromic(palindromicPoem))
		printf("\n是本篇回文诗\n");
	else
		printf("\n不是本篇回文诗\n");
	return 0;
}
int palindromic(char *palindromicPoem)
{
	char *forwardRead;
	char reverseRead[10000];
	int reverseIndex = 0, poemLen = strlen(palindromicPoem);
	forwardRead = palindromicPoem;
	printf("\n【正读】：\n");
	while (*forwardRead)
	{
		if (*forwardRead != ' ')
			putchar(*forwardRead);
		else
			putchar('\n');
		forwardRead++;
	}
	forwardRead--;
	if (*(forwardRead) == ' ')
	{
		*(forwardRead) = '\0';
		poemLen--;
		forwardRead--;
	}
	printf("\n【倒读】：\n");
	while (reverseIndex < poemLen)
	{
		if (*(forwardRead) != ' ')
		{
			forwardRead--;
			reverseRead[reverseIndex++] = *forwardRead;
			reverseRead[reverseIndex++] = *(forwardRead + 1);
			forwardRead--;
		}
		else
		{
			reverseRead[reverseIndex++] = ' ';
			forwardRead--;
		}
	}
	reverseRead[reverseIndex] = '\0';
	for (reverseIndex = 0; reverseIndex < poemLen; reverseIndex++)
		if (reverseRead[reverseIndex] != ' ')
			putchar(reverseRead[reverseIndex]);
		else
			putchar('\n');
	putchar('\n');
	if (strcmp(palindromicPoem, reverseRead) == 0)
		return 1;
	else
		return 0;
}
