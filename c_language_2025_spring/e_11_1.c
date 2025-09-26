
// Chapter 11

// Example 11-1: 奥运5环的颜色信息

#include <stdio.h>
#include <string.h>

typedef char *string; // 8个字节

void print_colors(string colors[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s -> %d\n", colors[i], strlen(colors[i]));
    }
}

void swap(string *a, string *b)
{
    // 二级指针
    string temp = *a;
    *a = *b;
    *b = temp;
}

void sort_colors(string colors[], int n)
{
    // Bubble sort with improved version
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(colors[j], colors[j + 1]) > 0)
            {
                swap(&colors[j], &colors[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

void sort_colors_by_len(string colors[], int n)
{
    // Bubble sort with improved version
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strlen(colors[j]) > strlen(colors[j + 1]))
            {
                swap(&colors[j], &colors[j + 1]);
                flag = 1;
            }
            else if (strlen(colors[j]) == strlen(colors[j + 1]))
            {
                if (strcmp(colors[j], colors[j + 1]) > 0)
                {
                    swap(&colors[j], &colors[j + 1]);
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

int brute_force_search(string colors[], int n, string key)
{
    // Brute force
    for (int i = 0; i < n; i++)
    {
        if (strcmp(colors[i], key) == 0)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    string colors[5] = {"Blue", "Black", "Red", "Yellow", "Green"};
    int n = sizeof(colors) / sizeof(colors[0]);
    char* target = "Blue";

    // sort_colors(colors, n);
    sort_colors_by_len(colors, n);
    print_colors(colors, n);

    printf("Search for 'Red': %d\n", brute_force_search(colors, n, target));

    return 0;
}
