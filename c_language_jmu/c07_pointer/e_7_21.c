#include <stdio.h>
int main()
{
	char *strDelChar(char *, char);
	char sourceStr[100];
	char delChar;
	int idx, num;
	printf("请输入字符串：");
	gets(sourceStr);
	printf("请输入要删除的字符：");
	delChar = getchar();
	printf("吃掉字符%c以后的结果：", delChar);
	puts(strDelChar(sourceStr, delChar));
	return 0;
}
char *strDelChar(char *sourceStr, char delChar)
{
	char *targetStr, *result;
	targetStr = result = sourceStr;
	while (*sourceStr)
	{
		if (*sourceStr != delChar)
			*targetStr++ = *sourceStr;
		sourceStr++;
	}
	*targetStr = '\0';
	return result;
}
