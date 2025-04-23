#include <stdio.h>
int main()
{
	int i, j;
	for (i = 1; i <= 9; i++) // 外循环
	{
		for (j = 1; j <= i; j++) // 内循环
		{
			printf("%d*%d=%-4d", j, i, i * j); //-4d可以让输出值左对齐
		}
		printf("\n");
	}
	return 0;
}
