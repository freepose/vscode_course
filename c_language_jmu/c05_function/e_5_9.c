#include <stdio.h>
int main()
{
    int n, f;
    int fac(int n);
    printf("请输入n的值: ");
    scanf("%d", &n);
    f = fac(n);
    printf("%d!=%d\n", n, f);
    return 0;
}
int fac(int n)
{
    if (n != 1)
        return (fac(n - 1) * n);
    else
        return (1);
}
