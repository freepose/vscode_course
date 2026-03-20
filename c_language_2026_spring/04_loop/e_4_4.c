
// is prime number: 循环标记法

#include <stdio.h>

int main()
{
    int n = 6;

    int is_prime = 1; // Assume n is prime
    scanf("%d", &n);

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            is_prime = 0;
            break;
        }        
    }

    printf("%d is %s prime number.\n", n, is_prime ? "a" : "not a");

    return 0;
}