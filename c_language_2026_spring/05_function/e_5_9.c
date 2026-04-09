
#include <stdio.h>

int fact_iter(int);
int fact_recur(int);

int main()
{

    int n = 6;

    printf("%d! = %d\n", n, fact_iter(n));
    printf("%d! = %d\n", n, fact_recur(n));

    return 0;
}

int fact_iter(int n)
{
    int f = 1;

    for (int i = 1; i <= n; i++)
    {
        f *= i;
    }

    return f;
}

int fact_recur(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    return n * fact_recur(n - 1);
}
