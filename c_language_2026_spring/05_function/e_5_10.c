
// example 5-10 Hanio

// #include <stdio.h>

// void hanoi(int n, char from, char to, char aux)
// {
//     if (n == 1)
//     {
//         printf("Move disk 1 from %c to %c\n", from, to);
//     }
//     else
//     {
//         hanoi(n - 1, from, aux, to); // 将n-1个盘子从from移动到aux
//         printf("Move disk %d from %c to %c\n", n, from, to); // 将第n个盘子从from移动到to
//         hanoi(n - 1, aux, to, from); // 将n-1个盘子从aux移动到to
//     }
// }

// int main()
// {
//     int n = 3; // 盘子数量
//     hanoi(n, 'A', 'B', 'C'); // 将n个盘子从柱子A移动到柱子B，使用柱子C作为辅助
//     return 0;
// }

#include <stdio.h>

void print_multiplication_table(int n)
{
    if (n == 1)
    {
        printf("1*1=1\n");
    }
    else
    {
        print_multiplication_table(n - 1); // 打印前n-1行的乘法表
        for (int i = 1; i <= n; i++)
        {
            printf("%d*%d=%d ", i, n, i * n); // 打印第n行的乘法表
        }
        printf("\n");
    }
}

int main()
{
    int n = 9; // 乘法表的大小
    print_multiplication_table(n); // 打印n*9的乘法表
    return 0;
}
