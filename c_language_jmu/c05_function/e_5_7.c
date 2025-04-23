#include <stdio.h>
extern int x;
int main()
{
	int i;
	void Fun();
	for (i = 1; i < 5; i++)
	{
		++x;
		printf("%d,", x);
		Fun();
	}
	return 0;
}
int x = 1; // 全局变量x
void Fun()
{
	static int x = 10; // 静态局部变量x
	++x;
	printf("%d\n", x);
}
