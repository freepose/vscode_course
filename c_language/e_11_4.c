
// Example 11-4, 用二维数组存储奥运五环字符串

#include <stdio.h>
#include <string.h>

void print_colors_2d(char colors[][7], int size)
{
    // This is an 2d array of char type
    for (int i = 0; i < size; i++)
    {
        printf("%s -> %d\n", colors[i], strlen(colors[i]));
    }
}

void sort_colors_2d(char colors_2d[][7], int size)
{
    // Bubble sort with improved version
    for (int i = 0; i < size - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (strcmp(colors_2d[j], colors_2d[j + 1]) > 0)
            {
                char temp[7];
                strcpy(temp, colors_2d[j]);
                strcpy(colors_2d[j], colors_2d[j + 1]);
                strcpy(colors_2d[j + 1], temp);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

void sort_colors_2d_by_len(char colors_2d[][7], int size)
{
    // Bubble sort with improved version
    for (int i = 0; i < size - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (strlen(colors_2d[j]) > strlen(colors_2d[j + 1]))
            {
                char temp[7];
                strcpy(temp, colors_2d[j]);
                strcpy(colors_2d[j], colors_2d[j + 1]);
                strcpy(colors_2d[j + 1], temp);
                flag = 1;
            }
            else if (strlen(colors_2d[j]) == strlen(colors_2d[j + 1]))
            {
                if (strcmp(colors_2d[j], colors_2d[j + 1]) > 0)
                {
                    char temp[7];
                    strcpy(temp, colors_2d[j]);
                    strcpy(colors_2d[j], colors_2d[j + 1]);
                    strcpy(colors_2d[j + 1], temp);
                    flag = 1;
                }
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

int main()
{
    char colors_2d[][7] = {"Blue", "Yellow", "Green", "Black", "Red"};
    int n_colors = 5;

    // sort_colors_2d(colors_2d, n_colors);

    sort_colors_2d_by_len(colors_2d, n_colors);

    print_colors_2d(colors_2d, n_colors);


    return 0;
}