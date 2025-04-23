
// Example 8-5: Bubble Sort.
// Input n positive integers, sort them in ascending order, and output them using the bubble sort algorithm.

#include <stdio.h>

#define MAXN 10

void swap(int *px, int *py);

void bubble(int a[], int n);

int main(void)
{
    int n, a[MAXN];
    int i;

    printf("Enter n (n<=10): ");
    scanf("%d", &n);
    printf("Enter %d integers: ", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    bubble(a, n);
    printf("After sorted: ");
    for (i = 0; i < n; i++)
    {
        printf("%3d", a[i]);
    }

    return 0;
}

void swap(int *px, int *py)
{
    int t;

    t = *px;
    *px = *py;
    *py = t;
}

void bubble(int a[], int n)
{
    int i, j, t;

    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

// Enter n (n<=10): 8
// Enter 8 integers: 7 3 66 3 -5 22 -77 2
// After sorted: -77 -5  2  3  3  7 22 66