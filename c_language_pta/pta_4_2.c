
#include <stdio.h>
#include <math.h>

int main()
{
    int n = 0;
    double fact = 1;
    double sum = 0;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        fact *= i;  
        sum += fact;
    }

    printf("%.0f", sum);

    return 0;
}