
// Example 7-6: Survey on the popularity of TV programs.
// A TV station wants to survey the popularity of 8 programs (with corresponding program numbers from 1 to 8) among viewers. A total of n viewers (1≤n≤1000) are surveyed, and each viewer can only vote for one favorite program. The program requires inputting the voting situation of each viewer and outputting the voting results for each program.

#include <stdio.h>

#define MAXN 8
int main()
{
    int i, n, response;
    int count[MAXN + 1];

    printf("Enter n: ");
    scanf("%d", &n);
    for (i = 1; i <= MAXN; i++)
    {
        count[i] = 0;
    }
    for (i = 1; i <= n; i++)
    {
        printf("Enter your response: ");
        scanf("%d", &response);
        if (response >= 1 && response <= MAXN)
        {
            count[response]++;
        }
        else
        {
            printf("invalid: %d\n", response);
        }
    }
    printf("result:\n");
    for (i = 1; i <= MAXN; i++)
    {
        if (count[i] != 0)
        {
            printf("%4d%4d\n", i, count[i]);
        }
    }

    return 0;
}

// Enter n: 6
// Enter your response: 3
// Enter your response: 1
// Enter your response: 6
// Enter your response: 9
// invalid: 9
// Enter your response: 8
// Enter your response: 1
// result:
//    1   2
//    3   1
//    6   1
//    8   1