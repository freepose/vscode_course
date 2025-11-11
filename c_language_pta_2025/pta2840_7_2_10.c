#include <stdio.h>

int all_match(char arr[][100], int number)
{
    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number; j++)
        {
            if (arr[i][j] != '*')
            {
                return 0;
            }
        }
    }
    return 1;
}

void print_array2d(char arr[][100], int number)
{
    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number; j++)
        {
            printf("%c", arr[i][j]);
            if (j < number - 1) printf(" ");
        }
        printf("\n");
    }
}

int main()
{
    int N; // 1 <= N < 5
    int K;
    char arr[100][100] = {0};

    if (scanf("%d", &N) != 1) return 0;
    int size = 2 * N;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf(" %c", &arr[i][j]); // 跳过空白读取字母
        }
    }

    if (scanf("%d", &K) != 1) return 0;

    int mismatch_counter = 0;

    for (int step = 0; step < K; step++)
    {
        int x1, y1, x2, y2;
        if (scanf("%d %d %d %d", &x1, &y1, &x2, &y2) != 4) break;

        // 转 0-based
        x1--; y1--; x2--; y2--;

        // 坐标越界当作错误一次
        if (x1 < 0 || x1 >= size || y1 < 0 || y1 >= size ||
            x2 < 0 || x2 >= size || y2 < 0 || y2 >= size)
        {
            mismatch_counter++;
            printf("Uh-oh\n");
            if (mismatch_counter >= 3)
            {
                printf("Game Over\n");
                return 0;
            }
            continue;
        }

        if (arr[x1][y1] == arr[x2][y2] && arr[x1][y1] != '*')
        {
            arr[x1][y1] = '*';
            arr[x2][y2] = '*';
            print_array2d(arr, size);

            if (all_match(arr, size))
            {
                printf("Congratulations!\n");
                return 0;
            }
        }
        else
        {
            mismatch_counter++;
            printf("Uh-oh\n");
            if (mismatch_counter >= 3)
            {
                printf("Game Over\n");
                return 0;
            }
        }
    }

    // 若没提前结束，按最终状态补充判定
    if (mismatch_counter >= 3)
    {
        printf("Game Over\n");
    }
    else if (all_match(arr, size))
    {
        printf("Congratulations!\n");
    }

    return 0;
}