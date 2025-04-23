#include <stdio.h>
#define ROW 4
int main()
{
	char acrosticStr[ROW][20];
	int row;
	printf("请输入诗句:\n");
	// 按行输入，数组acrosticStr只带一个下标，表示一行
	for (row = 0; row < ROW; row++)
		gets(acrosticStr[row]);

	// 输出每行首个汉字，一个汉字占两个字节，用两个字符表示一个汉字
	printf("\n诗句每行首字组成:\n");
	for (row = 0; row < ROW; row++)
		printf("%c%c", acrosticStr[row][0], acrosticStr[row][1]);
	return 0;
}
