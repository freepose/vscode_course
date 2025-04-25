
// Chapter 10: Functions to the advances

// Example 10-0: Recall the previous example on factor calculation (i.e., n!)

#include <stdio.h>

int factorial(int n)
{
    // �õݹ�ķ�ʽ��ʵ��
    if (n == 0 || n == 1)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

int main()
{
    int n = 5;

    printf("%d! = %d\n", n, factorial(n));
    return 0;
}