
// Example 6-2: Relational expression example

#include <stdio.h>

int main(void)
{
    char ch = 'w';
    int a = 2, b = 3, c = 1, d, x = 10;

    printf("%d ", a > b == c);
    printf("%d ", d = a > b);
    printf("%d ", ch > 'a' + 1);
    printf("%d ", d = a + b > c);
    printf("%d ", b - 1 == a != c);
    printf("%d\n", 3 <= x <= 5);

    return 0;
}

// 0 0 1 1 0 1