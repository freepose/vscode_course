
// Examples on loop advanced.

#include <stdio.h>

int is_prime(int n)
{
    /// @brief Check if a number is prime. 循环标记法：condition in a loop
    /// @param n : the number to check.

    if (n < 2)
    {
        return 0; // 0 and 1 are not prime numbers
    } 
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0) return 0; // n is divisible by i, so it's not prime
    }
    return 1; // n is prime
}

int main()
{
    int n = 10;

    // Linearly loop
    for (int i = 1; i <= n; i++)    
    {
        printf("i = %d\n", i);
    }

    // Nested loop
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("i = %d, j = %d\n", i, j);
        }
    }

    // 1. 循环累计法：accumulation in a loop
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i; // sum = sum + i;
    }
    printf("Sum = %d\n", sum);

    // 1.1. 循环计数法：counting in a loop
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        count++; // count = count + 1;
    }
    printf("Count = %d\n", count);

    // 1.2. 循环累计法：accumulation in a loop with steps
    int step = 2;
    int sum_with_steps = 0;
    for (int i = 1; i <= n; i += step)
    {
        sum_with_steps += i; // sum_with_steps = sum_with_steps + i;
    }
    printf("Sum with steps = %d\n", sum_with_steps);

    // 2. 循环标记法：condition in a loop, is_prime
    if (is_prime(n))
    {
        printf("%d is a prime number.\n", n);
    }
    else
    {
        printf("%d is not a prime number.\n", n);
    }

    // 3. 辗转求余法：get digits of a number using *while* loop
    int number = 250;
    do 
    {
        printf("%d ", number % 10); // Print the last digit
        number /= 10; 
    } while (number > 0);

    // 3.1. Greatest common divisor (GCD) using *while* loop
    int a = 48, b = 18; // assure a > b
    while (b != 0)
    {
        int temp = b;
        b = a % b; // Remainder
        a = temp;  // Update a to the previous b
    }
    printf("\nGCD = %d\n", a); // GCD is in a

    // 3.2. 辗转求和法：fibonacci sequence using *for* loop
    int fib1 = 0, fib2 = 1, fib_next;
    printf("Fibonacci sequence: %d %d ", fib1, fib2);
    for (int i = 3; i <= n; i++)
    {
        fib_next = fib1 + fib2;
        printf("%d ", fib_next);
        fib1 = fib2; // Update fib1 to the previous fib2
        fib2 = fib_next; // Update fib2 to the next number
    }
    printf("\n");

    return 0;
}