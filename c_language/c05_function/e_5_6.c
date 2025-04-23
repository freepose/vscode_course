
// Example 5-6: This program outputs a number pyramid. It takes a positive integer n as input and outputs n rows of the number pyramid.

#include <stdio.h>

void pyramid(int n);

int main(void)
{
    int n;

    printf("Enter n: ");
    scanf("%d", &n);
    pyramid(n);

    return 0;
}

void pyramid(int n)
{
    int i, j;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n - i; j++)
        {
            printf(" ");
        }
        for (j = 1; j <= i; j++)
        {
            printf("%d ", i);
        }
        putchar('\n');
    }

    return;
}

// Enter n: 5
//     1 
//    2 2 
//   3 3 3 
//  4 4 4 4 
// 5 5 5 5 5