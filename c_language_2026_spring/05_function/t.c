#include <stdio.h>
#include <math.h>

int prime( int p );
int PrimeSum( int m, int n );
    
int main()
{
    int m, n, p;

    scanf("%d %d", &m, &n);
    printf("Sum of ( ");
    for( p=m; p<=n; p++ ) {
        if( prime(p) != 0 )
            printf("%d ", p);
    }
    printf(") = %d\n", PrimeSum(m, n));

    return 0;
}

/* 你的代码将被嵌在这里 */


int prime(int p)
{
    if (p < 2)
    {
        return 0;
    }
    
    for (int i = 2; i * i <= p; i++)  // 优化判断范围到 sqrt(p)
    {
        if (p % i == 0)
        {
            return 0; 
        }
    }
    return 1; 
}

int PrimeSum(int m, int n)
{
   int k, sum = 0;
   for (k = m; k <= n; k++)
   {
       if (prime(k))  // 如果 k 是素数
       {
           sum += k;  // 累加素数的值
       }
    }
    return sum;
}

