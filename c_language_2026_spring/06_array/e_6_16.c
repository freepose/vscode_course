
#include <stdio.h>

void print_array_int(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void bubble_sort_desc(int a[], int n)
{
    for (int i = 0; i < 10 - 1; i++)
    {
        for (int j = 0; j < 10 - 1 - i; j++)
        {
            if (a[j] < a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void selection_sort_desc(int a[], int n)
{
    for (int j = 0; j < 10; j++)
    {
        int index = j;
        for (int i = j + 1; i < 10; i++)
        {
            if (a[index] < a[i])
            {
                index = i;
            }
        }

        if (index != j)
        {
            int temp = a[index];
            a[index] = a[j];
            a[j] = temp;
        }
    }
}

int main()
{
    int scores[10] = {67, 88, 76, 90, 56, 95, 72, 83, 80, 92};

    print_array_int(scores, 10);
    // bubble_sort_desc(scores, 10);
    selection_sort_desc(scores, 10);
    print_array_int(scores, 10);

    return 0;
}