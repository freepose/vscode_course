#include <stdio.h>
int main()
{
	char sourceStr[] = {'C', ' ', 'p', 'r', 'o', 'g', 'r', 'a', 'm', '\0'}, targetStr[10];
	int i;
	for (i = 8; i >= 0; i--)
		targetStr[8 - i] = sourceStr[i];
	targetStr[9] = '\0'; // 字符串结束标志
	for (i = 0; i < 10; i++)
		printf("%c", targetStr[i]);
	printf("\n");
	return 0;
}
