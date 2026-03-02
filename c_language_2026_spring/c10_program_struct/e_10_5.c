
// Example 10-4: Write a recursive function to solve the Tower of Hanoi problem.

#include <stdio.h>

void hanio(int n, char a, char b, char c);
int main(void)
{
    int n;

    printf("input the number of disk: ");
    scanf("%d", &n);
    printf("the steps for %d disk are:\n", n);
    hanio(n, 'a', 'b', 'c');

    return 0;
}

void hanio(int n, char a, char b, char c)
{
    if (n == 1)
    {
        printf("%c-->%c\n", a, b);
    }
    else
    {
        hanio(n - 1, a, c, b);
        printf("%c-->%c\n", a, b);
        hanio(n - 1, c, b, a);
    }
}

// input the number of disk: 3
// the steps for 3 disk are:
// a-->b
// a-->c
// b-->c
// a-->b
// c-->a
// c-->b
// a-->b