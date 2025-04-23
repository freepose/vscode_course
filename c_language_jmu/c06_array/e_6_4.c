#include <stdio.h>
int main()
{
	char c[26], ch;
	int i;
	for (ch = 'a'; ch <= 'z'; ch++)
		c[ch - 'a'] = ch;
	printf("数组元素依次为：\n");
	for (i = 0; i < 26; i++)
		printf("%c ", c[i]);
	return 0;
}
