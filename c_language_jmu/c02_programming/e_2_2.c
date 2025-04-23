#include <stdio.h>
#include <limits.h>
int main()
{
	printf("int类型占用字节数：%d\n", sizeof(int));
	printf("short int类型占用字节数：%d\n", sizeof(short int));
	printf("long int类型占用字节数：%d\n", sizeof(long int));
	printf("基本整型最小值: %d, 基本整型最大值: %d\n", INT_MIN, INT_MAX);
	printf("短整型最小值: %d, 短整型最大值: %d\n", SHRT_MIN, SHRT_MAX);
	printf("无符号短整型最大值: %u, 无符号整型最大值: %u\n", USHRT_MAX, UINT_MAX);
	return 0;
}
