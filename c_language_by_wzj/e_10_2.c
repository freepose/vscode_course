
// Example 10-2: hanio tower

#include <stdio.h>

void hanio(int n, char a, char b, char c)
{
    if (n == 1)
    {
        printf("%c -> %c\n", a, b);
    }
    else
    {
        hanio(n - 1, a, c, b);
        printf("%c -> %c\n", a, b);
        hanio(n - 1, c, b, a);
    }
}

int main()
{
    int n = 10;
    hanio(n, 'A', 'B', 'C');

    return 0;
}