
#include <stdio.h>

#define N 10

void selection_sort(int a[], int n)
{
    for (int j = 0; j < N - 1; j++)
    {
        int index = j;
        for (int i = j + 1; i < N; i++)
        {
            if (a[index] > a[i]) // ascending
            {
                index = i;
            }
        }

        // swap
        int temp = a[j];
        a[j] = a[index];
        a[index] = temp;
    }
}

void bubble_sort(int a[], int n)
{
    for (int j = 0; j < N - 1; j++)
    {
        for (int i = 0; i < N - 1 - j; i++)
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

int brute_force_search(int a[], int n, int x)
{
    int index = -1;
    for (int i = N - 1; i >= 0; i--)
    {
        if (x == a[i])
        {
            index = i;
        }
    }

    return index;
}

int binary_search(int sorted_array[], int n, int x)
{
    int mid, low = 0, high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (sorted_array[mid] == x)
        {
            return mid;
        }
        else if (sorted_array[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

void print_array(int a[], int n)
{
    for (int i = 0; i < N; i++)
    {
        // printf("%p -> a[%d] -> %d\n", &a[i], i, a[i]);
        printf("%d\t", a[i]);
    }
    printf("\n");
}

int main()
{
    int a[N] = {55, 23, 8, 11, 22, 89, 0, -1, 78, 186};

    int x = 78;

    print_array(a, N);
    // selection_sort(a, N);
    // bubble_sort(a, N);
    // print_array(a, N);

    // int index = brute_force_search(a, N, x);

    bubble_sort(a, N);
    int index = binary_search(a, N, x);
    print_array(a, N);

    if (index > -1)
    {
        printf("Find x = %d at a[%d]\n", x, index);
    }
    else
    {
        printf("Not found!\n");
    }

    return 0;
}