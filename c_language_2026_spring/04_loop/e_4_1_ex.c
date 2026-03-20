
// Factorial function

#include <stdio.h>

int main()
{
    int product = 1;
    int start = 1, end = 6;

    for (int i = start; i <= end; i++)
    {
        product *= i; 
    }

    printf("%d! = %d\n", end, product);

    return 0;
}