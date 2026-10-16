
// 循环累计法

#include <stdio.h>

int main()
{
    int n = 100, sum = 0;

    for (int i = 0; i <= n; i = i + 4)
    {
        sum += i;
        printf("i = %d, sum = %d\n", i, sum);
    }

    printf("sum(1...%d) = %d\n", n, sum);

    return 0;
}

// #include <stdio.h>

// int main()
// {

//     int n = 6, fact = 1;

//     for (int i = 1; i <= n; i = i + 1)
//     {
//         fact *= i;
//     }

//     printf("%d! = %d\n", n, fact);

//     return 0;
// }