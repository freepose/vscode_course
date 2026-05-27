
// 通过指针变量来访问一维数组的元素：通过数组名+偏移量

#include <stdio.h>

void print_array_v1(int a[], int n)
{
    // 通过数组的方式
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void print_array_v2(int *p, int n)
{
    // 传递一个地址进来，以及告诉你有几个元素
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", *(p + i));
    }
    printf("\n");
}

void bubble_sort(int a[], int n)
{
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < n - 1 - j; i++)
        {
            if (a[i] > a[i + 1])
            {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
}

int main()
{
    int scores[10] = {67, 88, 76, 90, 56, 95, 72, 83, 80, 92};


    print_array_v2(scores, 10);

    bubble_sort(&scores[3], 5);
    
    print_array_v2(scores, 10);

    return 0;
}