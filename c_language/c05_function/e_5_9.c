
// Example 5-9: This program calculates the factorial of numbers from 1 to n using a function with a static variable.
// The function fact_s(int n) computes the factorial of n, and the main function takes an integer n as input and outputs the factorials from 1! to n!.

#include <stdio.h>

double fact_s(int n);

int main(void)
{
    int i, n;

    printf("Input n:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("%3d!=%.0f\n", i, fact_s(i));
    }

    return 0;
}

double fact_s(int n)
{
    static double f = 1;

    f = f * n;

    return (f);
}

// Input n:6
//  1!=1
//  2!=2
//  3!=6
//  4!=24
//  5!=120
//  6!=720