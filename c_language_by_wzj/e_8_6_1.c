
// 传递一个二维数组到函数中

#include <stdio.h>

// void print_2d_array(int array[][13], int rows, int cols)

void print_2d_array(int (*array)[13], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int month_days[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };

    print_2d_array(month_days, 2, 13);

    return 0;
}