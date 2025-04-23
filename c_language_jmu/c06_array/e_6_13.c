#include <stdio.h>
#include <string.h>
int main()
{
	char sourceStr[100], targetStr[100] = "";
	int i, myLength;
	printf("请输入字符串：");
	gets(sourceStr);
	myLength = strlen(sourceStr); // myLength为输入的字符串的长度
	for (i = myLength - 1; i >= 0; i--)
		targetStr[myLength - 1 - i] = sourceStr[i];
	printf("反转后的字符串：");
	puts(targetStr);
	return 0;
}
