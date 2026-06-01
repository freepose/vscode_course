
// // What is a pointer?

// #include <stdio.h>

// int main()
// {
//     int n = 123;
//     int *p = &n;

//     printf("%p -> %d\n", p, n);
//     *p = 456;
//     printf("n = %d", n);

//     return 0;
// }
#include <stdio.h>

int main()
{
    char *strs[] = {"Hello", "World", "C", "Programming"}; // 定义一个指针字符串数组

    for (int i = 0; i < 4; i++)
    {
        printf("%s ", strs[i]); // 输出指针字符串数组的元素
    }

    return 0;
}