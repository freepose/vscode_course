
// 给定某数字A（1≤A≤9）以及非负整数N（0≤N≤100000），求数列之和S=A+AA+AAA+⋯+AA⋯A（N个A）。例如A=1, N=3时，S=1+11+111=123。

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int A, N;
    int *sum_array = 0;

    scanf("%d %d", &A, &N);

    if (N == 0)
    {
        printf("0");
        return 0;
    }
    

    sum_array = (int *)malloc(sizeof(int) * (N + 1));
    memset(sum_array, 0, sizeof(int) * (N + 1));  

    int carry = 0;
    for (int i = 0; i < N ; i++)
    {
        int temp = (N - i) * A + carry;
        sum_array[i] = temp % 10;
        carry = temp / 10;
    }

    if (carry > 0)
    {
        sum_array[N] = carry;
    }

    // reverse output: print values from index N to index 0 when the first zero is encountered
    int first_zero = 0;
    for (int i = N; i >= 0; i--)
    {
        if (first_zero == 0 && sum_array[i] > 0)
        {
            first_zero = 1;
        }

        if (first_zero == 1)
        {
            printf("%d", sum_array[i]);
        }
    }

    return 0;
}