

#include <stdio.h>

int is_even(int n) { return n % 2 == 0; }

int main()
{
    int n = 3;
    scanf("%d", &n);
    if (is_even(n))
    {
        printf("%d is even\n", n);
    }
    else
    {
        printf("%d is odd\n", n);
    }
    return 0;
}
