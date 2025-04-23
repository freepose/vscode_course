#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fp; // 文件指针变量fp
	struct GDP
	{
		int year;  // 存储年份
		int value; // 人均国内生产总值
	} pcGDP[5], display[5];

	int i;

	/*以写新二进制文件形式打开文件，并且可读 */
	if ((fp = fopen("PCGDP.dat", "wb+")) == NULL)
	{
		printf("文件打开错误！\n");
		exit(0);
	}

	for (i = 0; i < 5; i++)
	{
		printf("请输入年份和人均国内生产总值：");
		scanf("%d %d", &pcGDP[i].year, &pcGDP[i].value);
	}
	fwrite(pcGDP, sizeof(pcGDP), 1, fp);
	printf("人均国内生产总值信息已写入文件中\n");

	rewind(fp); // 重新定位文件当前位置到文件的开头
	fread(display, sizeof(display), 1, fp);
	printf("年份\t人均国内生产总值：\n");
	for (i = 0; i < 5; i++)
	{
		printf("%d\t%d\n", display[i].year, display[i].value);
	}
	fclose(fp); // 关闭文件
	return 0;
}
