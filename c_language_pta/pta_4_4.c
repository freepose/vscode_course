
// Chapter 4: pta 4-4

#include<stdio.h>

int main()
{
    int stars = 19;
    int n = 1;

    scanf("%d", &stars);

    while (2*n*n - 1 <= stars)
    {
        n++;
    }
    n--;
    
    for (int i = 1; i <= n; i++)
    {
        for (int k=1; k <= i - 1; k++)
        {
            printf(" ");
        }
        for (int j = 1; j <= 2*(n - i) + 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    for (int i = 2; i <= n; i++)
    {
        for (int k=1; k <= n - i; k++)
        {
            printf(" ");
        }
        for (int j = 1; j <= 2*i - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    printf("%d", stars - 2*n*n + 1);
    return 0;
}