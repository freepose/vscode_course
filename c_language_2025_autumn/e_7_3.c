
// Example 7-3: Brute Force (BF) search 暴力搜索

// 原理：就是数组的第一个元素开始搜索，依次和目标值比较，直到找到目标值（或数据最后一个元素）为止。

#include <stdio.h>

int main()
{
    int arr[10] = {2, 9, 8, 1, 9};
    int n = 5;
    int x = 9; // target value
    int is_found = 0;   // 标记法, 0表示没有找到, 1表示找到了
    int index = -1;    // 下标法, -1表示没有找到, 其他值表示找到了对应的下标

    // print the fibonacci sequence
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // 循环标记法
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            is_found = 1;
            index = i;
            break;
        }
    }

    if (is_found)
    {
        printf("Found x = %d at index %d\n", x, index);
    }
    else
    {
        printf("Not Found\n");
    }

    return 0;
}