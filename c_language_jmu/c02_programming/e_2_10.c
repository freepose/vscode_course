#include <stdio.h>
int main()
{
	int x = 12345;
	printf("x=%d;\n", x);
	printf("x=%+d;\n", x);
	printf("x=% d;\n", x); // 注意%和d之间有一个空格
	printf("x=%10d;\n", x);
	printf("x=%+10d;\n", x);
	printf("x=%-10d;\n", x);
	printf("x=%-+10d;\n", x);
	printf("x=%x;\n", x);
	printf("x=%#10x;\n", x);
	return 0;
}
