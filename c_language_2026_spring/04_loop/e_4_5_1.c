
// Greatest Common Divisor (GCD) of two numbers using Euclidean algorithm

#include <stdio.h>

int main()
{
    int a = 96, b = 42, temp;

    // while (b != 0)
    // {
    //     temp = a % b;
    //     a = b;
    //     b = temp;
    // }

    do {
        temp = a % b;
        a = b;
        b = temp;
    } while (b != 0);

    printf("GCD = %d\n", a);

    return 0;
}