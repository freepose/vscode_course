#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fp;	   // 文件指针变量fp
	int numCh = 0; // 记录文件中字符的个数
	char ch;
	/*以只读形式打开文件*/
	if ((fp = fopen("China.txt", "r")) == NULL)
	{
		printf("文件打开错误！\n");
		exit(0);
	}
	/*使用fgetc()函数统计字符个数*/
	ch = fgetc(fp); // 先从文件读取一个字符
	while (ch != EOF)
	{
		numCh++;		// 字符个数+1
		ch = fgetc(fp); // 从文件读取下一个字符
	}
	printf("文件中字符个数为：%d\n", numCh);
	fclose(fp); // 关闭文件
	return 0;
}
