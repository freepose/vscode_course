
// fibonacci using array

#include <stdio.h>

#define N 10

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

int main()
{
    int a[N + 10] = {55, 23, 8, 11, 22, 89, 0, -1, 78, 186};

    print_array(a, N);
    select_sort(a, N);
    print_array(a, N);

    return 0;
}