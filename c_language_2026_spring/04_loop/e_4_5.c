
// 循环：逆序输出数字

#include <stdio.h>
#include <math.h>

int main()
{
    int n = 12345;
    int reverse_n = 0;

    while (n > 0)
    {
        printf("%d ", n % 10);
        reverse_n = reverse_n * 10 + n % 10;
        n = n / 10;
    }

    printf("\nReverse n = %d\n", reverse_n);

    return 0;
}