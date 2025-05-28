
// prime numbers in [1, 100]，用了两次循环标记法

#include <stdio.h>

int is_prime(int n)
{
    // 循环标记法
    int flag = 1;

    if (n == 1)
    {
        flag = 0;   // mark as not prime
    }

    for (int i = 2; i <= n - 1; i++)
    {
        if (n % i == 0)
        {
            flag = 0;   // mark as not prime
            break;
        }
    }
    return flag;
}

int main()
{
    int start = 1, end = 100;

    // 循环标记法
    for (int i = start; i <= end; i++)
    {
        if (is_prime(i))
        {
            printf("%d ", i);
        }
    }
   
    return  0;
}