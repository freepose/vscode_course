
#include <stdio.h>
#include <math.h>

// 自定义的幂函数
int pow_func(int a, int x)
{
    for (int i = 1; i < x; i++)
    {
        a *= a;
    }
    return a;
}

int leap_year(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        return 1; // 闰年
    }
    else
    {
        return 0; // 平年
    }
}

int main()
{
    int a = 5;
    int x = 2;
    int year = 2026;
    
    printf("%d^%d = %d\n", a, x, (int)pow(a, x));
    printf("%d^%d = %d\n", a, x, pow_func(a, x));

    printf("year %d is %s\n", year, leap_year(year) ? "leap year" : "not leap year");

    return 0;
}