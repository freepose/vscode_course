
// pitia.cn, https://pintia.cn/problem-sets/1838054583869140992/problems/type/7?problemSetProblemId=1838054584081469441


#include <stdio.h>

void print_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        if (i < n - 1)
        {
            printf(" ");
        }
    }
    printf("\n");
}

void print_different_numbers_of_two_arrays(int a1[], int n1, int a2[], int n2)
{
    // print different numbers bewteen two arrays
    int c[40];
    int count = 0;

    for (int i = 0; i < n1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n2; j++)
        {
            if (a1[i] == a2[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            // printf("%d ", a1[i]);
            c[count] = a1[i];
            count++;
        }
    }

    for (int i = 0; i < n2; i++)
    {
        int flag = 0;
        for (int j = 0; j < n1; j++)
        {
            if (a2[i] == a1[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            // printf("%d ", a2[i]);
            c[count] = a2[i];
            count++;
        }
    }

    // 输出C的时候去掉重复的输出
    for (int i = 0; i < count; i++)
    {
        int flag = 0;
        for (int j = 0; j < i; j++)
        {
            if (c[i] == c[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            printf("%d", c[i]);
            if (i < count - 1)
            {
                printf(" ");
            }
        }
    }

}

int main()
{
    int n1, n2, a1[20], a2[20];

    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &a1[i]);
    }

    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &a2[i]);
    }

    print_different_numbers_of_two_arrays(a1, n1, a2, n2);
    
    return 0;
}