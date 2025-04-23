#include <stdio.h>
#include <string.h>
int main()
{
	char *palindromicPoem = "枯眼望遥山隔水 往来曾见几心知 壶空怕酌一杯酒 笔下难成和韵诗 途路阻人离别久 讯音无雁寄回迟 孤灯夜守长寥寂 夫忆妻兮父忆儿";
	char *forwardRead, *reverseRead;
	int poemLen;
	forwardRead = palindromicPoem;
	poemLen = strlen(palindromicPoem);
	reverseRead = palindromicPoem + poemLen - 2;
	printf("【正读】《思妻诗》\n");
	while (*forwardRead)
	{
		if (*forwardRead != ' ')
			putchar(*forwardRead);
		else
			putchar('\n');
		forwardRead++;
	}
	printf("\n【倒读】《思夫诗》\n");
	while (reverseRead >= palindromicPoem)
	{
		if (*(reverseRead + 1) != ' ')
		{
			putchar(*reverseRead);
			putchar(*(reverseRead + 1));
			reverseRead -= 2;
		}
		else
		{
			putchar('\n');
			reverseRead--;
		}
	}
	putchar('\n');
	return 0;
}
