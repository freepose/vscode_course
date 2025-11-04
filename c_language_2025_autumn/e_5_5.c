
// Example 5-5: is_prime() function

#include <stdio.h>

int is_prime(int n)
{
    if (n <= 1)
    {
        return 0;  
    }

    for (int i = 2; i * i <= n; i++)    // optimized loop condition
    {
        if (n % i == 0)
        {
            return 0;  
        }
    }

    return 0;   
}

double factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1.0;
    }

    return n * factorial(n - 1);
}

void to_digits(int n)
{
    if (n > 0)
    {
        to_digits(n / 10);       
        printf("%d ", n % 10); 
    }
}

int main()
{

    // int n = 20;
    // printf("%d! = %.0f\n", n, factorial(n));
    
    to_digits(123456);

    return 0;
}