
// 动态开辟数组 vs 静态开辟

#include <stdio.h>
#include <stdlib.h>

#define N 1024 * 1024 * 1024

void print_array_v2(int *p, int n)
{
    // 传递一个地址进来，以及告诉你有几个元素
    for (int i = 0; i < n; i++)
    {
    	if ((i+1) % (1024 * 1024) == 0)
    	{
    		printf("a[%d] -> %d\n", i, *(p + i));
		}
        
    }
    printf("\n");
}


int main()
{
//    int scores[N] = {67, 88, 76, 90, 56, 95, 72, 83, 80, 92};  // 静态开辟

	int *p = (int *)malloc(N * sizeof(int));

    print_array_v2(p, N);
    
    free(p);
    p = 0;

    return 0;
}