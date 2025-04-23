#include <stdio.h>
int main()
{
	int spiral[100][100] = {1}; // 初始化
	int row, myRow = 0;			// 行数
	int col, myCol = 0;			// 列数
	int ctrl = 0;				// 方向控制变量
	int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	// 方向数组，每行第一个元素表示纵向（上/下）的方向，第二个元素表示横向（左/右）的方向
	int i, j;
	int digit; // 螺旋形状上的数字
	printf("请输入螺旋的行数和列数（行列之间以空格间隔）：");
	scanf("%d%d", &row, &col);
	for (digit = 2; digit <= row * col; digit++)
	{
		myRow += direction[ctrl][0];
		myCol += direction[ctrl][1];
		spiral[myRow][myCol] = digit; // 填数
		if ((myRow == 0 && myCol == col - 1) || (myCol == col - 1 && myRow == row - 1) || (myRow == row - 1 && myCol == 0) ||
			spiral[myRow + direction[ctrl][0]][myCol + direction[ctrl][1]] != 0)
		// 方向控制判断语句
		{
			ctrl++; // 更改方向
			if (ctrl == 4)
				ctrl = 0; // 重置方向
		}
	}
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			printf("%4d", spiral[i][j]); // 输出
		printf("\n");
	}
	return 0;
}
