
# C05 函数

## 1. 函数的定义

函数是一个独立的代码块，可以被调用来执行特定的任务。函数的定义包括函数名、参数列表和函数体。

```c

#include <stdio.h>
#include <math.h>

// 自定义的幂函数
int pow_func(int a, int x)
{
    for (int i = 1; i < x; i++)
    {
        a *= a;
    }
    return a;
}

int main()
{
    int a = 5;
    int x = 2;
    printf("%d^%d = %d\n", a, x, (int)pow(a, x));
    printf("%d^%d = %d\n", a, x, pow_func(a, x));

    return 0;
}
```