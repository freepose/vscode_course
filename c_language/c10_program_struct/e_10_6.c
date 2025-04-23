
// Example 10-6: Use the divide-and-conquer method to solve the gold block problem

#include <stdio.h>

#define MAXN 101

int max(int a[], int m, int n);

int min(int a[], int m, int n);

int main(void)
{
    int i, n;
    int a[MAXN];

    printf("Enter n: ");
    scanf("%d", &n);
    if (n >= 2 && n <= MAXN - 1)
    {
        printf("Enter %d integers: ", n);
        for (i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        printf("max = %d\n", max(a, 0, n - 1));
        printf("min = %d\n", min(a, 0, n - 1));
    }
    else
    {
        printf("Invalid Value.\n");
    }

    return 0;
}

int max(int a[], int m, int n)
{
    int k, u, v;

    if (m == n)
    {
        return a[m];
    }
    k = (m + n) / 2;
    u = max(a, m, k);
    v = max(a, k + 1, n);

    return (u > v) ? u : v;
}

int min(int a[], int m, int n)
{
    int k, u, v;

    if (m == n)
    {
        return a[m];
    }
    k = (m + n) / 2;
    u = min(a, m, k);
    v = min(a, k + 1, n);

    return (u < v) ? u : v;
}
