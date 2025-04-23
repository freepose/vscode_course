#include<stdio.h>
int main(void)
{
    int i, n, flag = 1;

    printf("Enter a number: ");
    scanf("%d", &n);
    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            flag = 0;
            break;
        }
    }

    if (flag == 0)
    {
        printf("%d is not a prime number!\n", n);
    }
    else
    {
        printf("%d is a prime number!\n", n);
    }
    return 0;
}
