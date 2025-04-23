#include <stdio.h>
int main()
{
	short max = 32767, min = -32768;
	printf("初始时max和min的值分别为：%d, %d\n", max, min);
	max = max + 1;
	min = min - 1;
	printf("计算后max和min的值分别为：%d, %d\n", max, min);
	return 0;
}
