#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fp;	   // 文件指针变量fp
	int numCh = 0; // 记录文件中字符的个数
	/*以只读形式打开文件*/
	if ((fp = fopen("China.txt", "r")) == NULL)
	{
		printf("文件打开错误！\n");
		exit(0);
	}
	/*使用ftell()函数统计字符个数 */
	fseek(fp, 0, SEEK_END); // 先定位到文件末尾
	numCh = ftell(fp);		// 使用ftell()计算当前位置距离文件开头的位移量
	printf("文件中字符个数为：%d\n", numCh);
	fclose(fp); // 关闭文件
	return 0;
}
