#include <stdio.h>
int main()
{
	int grade;
	printf("请输入成绩：");
	scanf("%d", &grade);
	if (grade < 60)
	{				 // 注意一个大括号一行
		printf("E"); // 注意if内语句要缩进，使程序结构层次分明
	}
	return 0;
}
