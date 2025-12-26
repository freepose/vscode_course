

#include <stdio.h>

int main()
{
    int n, m;
    int a[20], b[20];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < n; i++)
    {
        // printf("%d ", a[i]);
    }
    int output[40], out_cnt = 0;
    // 标记已输出
    int used[40] = {0};
    // 先处理a数组中不在b中的元素
    for (int i = 0; i < n; i++)
    {
        int found = 0;
        for (int j = 0; j < m; j++)
        {
            if (a[i] == b[j])
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            // 检查是否已输出
            int already = 0;
            for (int k = 0; k < out_cnt; k++)
            {
                if (output[k] == a[i])
                {
                    already = 1;
                    break;
                }
            }
            if (!already)
            {
                output[out_cnt++] = a[i];
            }
        }
    }
    // 再处理b数组中不在a中的元素
    for (int i = 0; i < m; i++)
    {
        int found = 0;
        for (int j = 0; j < n; j++)
        {
            if (b[i] == a[j])
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            int already = 0;
            for (int k = 0; k < out_cnt; k++)
            {
                if (output[k] == b[i])
                {
                    already = 1;
                    break;
                }
            }
            if (!already)
            {
                output[out_cnt++] = b[i];
            }
        }
    }
    // 输出
    for (int i = 0; i < out_cnt; i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d", output[i]);
    }
    return 0;
}
