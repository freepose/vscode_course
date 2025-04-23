#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fpIn, *fpOut; // 文件指针变量
	char stuNo[20];		// 存储学生的学号
	char stuName[10];	// 存储学生的姓名
	int score;			// 考试成绩
	int max, min, avg, sum, count;
	char headLine[100]; // 用于存放文件标题行
	count = 0, sum = 0, max = 0, min = 100;

	if ((fpIn = fopen("scores.txt", "r")) == NULL)
	{
		printf("文件打开错误！\n");
		exit(0);
	}
	fgets(headLine, 100, fpIn); // 读取scores.txt文件标题行
	while (!feof(fpIn))			// 判断scores.txt文件是否结束
	{
		count = count + 1; // 每读取一行成绩信息，数量+1
		fscanf(fpIn, "%s %s %d", stuNo, stuName, &score);
		sum = sum + score; // 分数累加
		if (max < score)
			max = score; // 更新最高分
		if (min > score)
			min = score; // 更新最低分
	}
	avg = sum / count; // 计算平均分

	/*打开score_info.txt文件，写入数据*/
	if ((fpOut = fopen("score_info.txt", "w")) == NULL)
	{
		printf("文件打开错误！\n");
		exit(0);
	}
	/*fprintf按指定格式将数据写入文件中*/
	fprintf(fpOut, "平均分:%d\n最高分:%d\n最低分:%d\n", avg, max, min);
	printf("统计信息已写入文件\n");
	fclose(fpIn);
	fclose(fpOut);
	return 0;
}
