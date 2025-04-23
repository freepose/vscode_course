#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fp;		  // 文件指针变量fp
	char stuNo[20];	  // 存储学生的学号
	char stuName[10]; // 存储学生的姓名
	int score;		  // 考试成绩
	int i;

	// 打开文件scores.txt，文件名不带路径，需要和本程序在同一个目录下
	if ((fp = fopen("scores.txt", "w")) == NULL)
	{
		printf("文件打开错误！\n");
		exit(0); // 文件找不到，退出程序，使用exit()函数要包含stdlib.h文件
	}
	fprintf(fp, "学号\t姓名\t成绩"); // 在文件中写入标题行

	for (i = 0; i < 5; i++)
	{
		printf("请输入学生的学号、姓名和成绩：");
		scanf("%s %s %d", stuNo, stuName, &score);
		// 将学生成绩信息写入文件
		fprintf(fp, " \n%s\t%s\t%d ", stuNo, stuName, score);
	}
	printf("成绩信息已写入文件中\n");
	fclose(fp); // 关闭文件
	return 0;
}
