


// #include <stdio.h>


// int is_prime(int n)
// {
//     if (n == 1)
//     {
//         return 0;
//     }

//     for (int i = 2; i * i <= n; i++)
//     {
//         if (n % i == 0)
//         {
//             return 0;
//         }    
//     }
//     return 1;
// }

// int main()
// {
// 	int start = 1, end = 100, step = 1;
// 	int i = start;

//     while (i <= end)
//     {
//         if (is_prime(i) == 1)
//         {
//             printf("%d ", i);
//         }

//         i += step;
//     }
//     return 0;
// }

#include <stdio.h>

// 函数声明
int add(int a, int b);

int main()
{
    int x = 5, y = 10;
    printf("The sum of %d and %d is %d\n", x, y, add(x, y));
    return 0;
}

// 函数定义
int add(int a, int b)
{
    return a + b;
}