

// Example 3-2: 奇偶分家

#include <stdio.h>

int main()
{
    int n, i, temp;
    int odd_counter = 0, even_counter = 0;  // 计数器

    printf("Enter n: ");
    scanf("%d", &n);

    // Read n integers + 循环累计法 -> 循环条件累计法
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &temp);
        if (temp % 2 == 0)
        {
            even_counter++;
        }
        else
        {
            odd_counter++;
        }
    }
    printf("Odd: %d --- Even: %d\n", odd_counter, even_counter);
    return 0;
}