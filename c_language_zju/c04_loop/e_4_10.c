
// Example 4-10: Prime number problem.
// Input two positive integers m and n (1<=m<=n<=500) and output all prime numbers between m and n, with 10 numbers per line. A prime number is a positive integer that can only be divided by 1 and itself. 1 is not a prime number, and 2 is a prime number. Using nested loops to find all prime numbers between m and n.

#include <stdio.h>
#include <math.h>

int main(void)
{
    int count, i, k, flag, limit, m, n;

    printf("Enter m n: ");
    scanf("%d%d", &m, &n);
    count = 0;
    if (m < 1 || n > 500 || m > n)
    {
        printf("Invalid.\n");
    }
    else
    {
        for (k = m; k <= n; k++)
        {
            if (k <= 1)
            {
                flag = 0;
            }
            else if (k == 2)
            {
                flag = 1;
            }
            else
            {
                flag = 1;
                limit = sqrt(k) + 1;
                for (i = 2; i <= limit; i++)
                {
                    if (k % i == 0)
                    {
                        flag = 0;
                        break;
                    }
                }
            }
            if (flag == 1)
            {
                printf("%6d", k);
                count++;
                if (count % 10 == 0)
                {
                    printf("\n");
                }
            }
        }
    }

    return 0;
}

// Enter m n: 1 50
// 2    3    5    7   11   13   17   19   23   29
// 31   37   41   43   47