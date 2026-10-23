

#include <stdio.h>


int main()
{   
    double n = 6, sum = 0, fact = 1;

    for (int i = 1; i <= n; i++)
    {
        fact *= i;
        sum += fact;
    }

    printf("1! + 2! + ... + %d! = %.0lf\n", n, sum);

    return 0;
}