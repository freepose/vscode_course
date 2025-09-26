
#include <stdio.h>

int fact(int n)
{
    if (n > 1)
    {
        return n * fact(n - 1);
    }
    return 1;
}

void print_digits(int n)
{
    if (n > 0)
    {
        print_digits(n / 2);
        printf("%d ", n % 2);
    }
}

int main()
{
    // printf("%d! = %d\n", n, fact(5));
    print_digits(10);

    return 0;
}