#include <stdio.h>
int main()
{
	int n, m, k, indexOfChild, countOut = 0, countOff = 0;
	// countOut表示出列人数，countOff表示报数数字
	int childList[100] = {0}; // 数组元素值为0代表没出列，1代表出列
	int *childPoint = childList;
	printf("请输入参与游戏的小孩子的人数：");
	scanf("%d", &n);
	printf("请输入从哪个编号的小孩开始：");
	scanf("%d", &m);
	indexOfChild = m - 1;
	printf("请输入报数出列的数字：");
	scanf("%d", &k);
	printf("按报数顺序出列的小孩编号分别是：\n");
	while (countOut < n - 1)
	{
		if (childList[indexOfChild] == 0)
		{
			countOff++; // 报数
			if (countOff == k)
			{
				childList[indexOfChild] = 1; // 该孩子出列
				printf("%d  ", indexOfChild + 1);
				countOut++;	  // 出列人数增加1
				countOff = 0; // 重新报数
			}
		}
		indexOfChild = (++indexOfChild) % n;
	}
	while (*childPoint)
		childPoint++;
	printf("\n最后剩下的小孩编号是：%d\n", childPoint - childList + 1);
	return 0;
}
