#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fp; // 文件指针变量fp
	struct GDP
	{
		int year;			// 存储年份
		int value;			// 人均国内生产总值
	} pcGDP[5], display[5]; // 定义2个结构体数组

	int i;

	/*以写新文件形式打开文件 */
	if ((fp = fopen("PCGDP.dat", "wb")) == NULL)
	{
		printf("文件打开错误！\n");
		exit(0);
	}

	for (i = 0; i < 5; i++)
	{
		printf("请输入年份和人均国内生产总值：");
		scanf("%d %d", &pcGDP[i].year, &pcGDP[i].value);
	}
	/*使用fwrite()函数将结构体数组pcGDP的全部数据一次性写入文件中,
	fwrite()函数第一个参数为结构体数组起始地址，即数组名*/
	fwrite(pcGDP, sizeof(pcGDP), 1, fp);
	printf("人均国内生产总值信息已写入文件中\n");
	fclose(fp); // 关闭文件

	/*以只读形式打开文件 */
	if ((fp = fopen("PCGDP.dat", "rb")) == NULL)
	{
		printf("文件打开错误！\n");
		exit(0);
	}
	/*使用fread()函数从fp文件指针位置开始读取display数组长度数据到数组display中，
	fread()函数第一个参数为结构体数组起始地址，即数组名*/
	fread(display, sizeof(display), 1, fp);
	printf("年份\t人均国内生产总值：\n");
	for (i = 0; i < 5; i++)
	{
		printf("%d\t%d\n", display[i].year, display[i].value);
	}
	fclose(fp); // 关闭文件
	return 0;
}
