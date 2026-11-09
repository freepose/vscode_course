
// fibonacci using array

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10

void random_init_array(int a[], int n)
{
    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100 + 1;
    }
}

void print_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void select_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int j_mark = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j_mark] > a[j])
            {
                j_mark = j;
            }
        }
        // swap a[j_mark] with a[i]
        int t = a[j_mark];
        a[j_mark] = a[i];
        a[i] = t;
    }
}

int binary_search(int a[], int n, int x)
{
    int low = 0, hight = n - 1;

    while (low <= hight)
    {
        int mid = (low + hight) / 2;
        if (a[mid] < x)
        {
            low = mid + 1;
        }
        else if (a[mid] == x)
        {
            return mid;
        }
        else
        {
            hight = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int a[N + 10] = {2, 11, 19, 24, 26, 39, 70, 79, 90, 100};
    int x = 79;

    random_init_array(a, N);
    print_array(a, N);
    select_sort(a, N);
    print_array(a, N);

    int i = binary_search(a, N, x);

    if (i > 0)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }
    else
    {
        printf("Not found!\n");
    }

    return 0;
}