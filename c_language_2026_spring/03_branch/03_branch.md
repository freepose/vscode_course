
# C03 分支结构
---

## 通过阶梯水费的例子来理解分支结构

数学描述是：x是用水量，f(x)是水费，阶梯水费的计算公式如下：

```math
f(x) = \begin{cases}
    3x & \text{if } x \leq 50 \\
    4x - 50 & \text{if } x > 50
\end{cases}
```

当然，也有更复杂的阶梯水费计算公式，例如：

```math 
f(x) = \begin{cases}
    3x & \text{if } x \leq 50 \\
    4x - 50 & \text{if } 50 < x \leq 100 \\
    5x - 150 & \text{if } x > 100
\end{cases}
```


## 分支结构

### 单分支语句

``` cpp
// 交水费：异常
#include <stdio.h>

int main()
{
    int x = 0;
    float y = 0.0;

    scanf("%d", &x);

    if (x < 0)
    {
        printf("Error on input value!\n");
        return 0;
    }

    printf("f(%d) = %.2f\n", x, x * 3);

    return 0;
}
```

### 双分支语句

``` cpp
// 交水费：阶梯
#include <stdio.h>

int main()
{
    int x = 0;
    float y = 0.0;

    scanf("%d", &x);

    if (x <= 50)
    {
        y = 3 * x;
    }
    else
    {
        y = 4 * x - 50;
    }

    printf("f(%d) = %.2f\n", x, y);

    return 0;
}
```

### 多分支语句

``` cpp
// 交水费：多段
#include <stdio.h>

int main()
{
    int x = 0;
    float y = 0.0;

    scanf("%d", &x);

    if (x <= 50)
    {
        y = 3 * x;
    }
    else if (x <= 100)
    {
        y = 3 * 50 + 4 * (x - 50);
    }
    else
    {
        y = 3 * 50 + 4 * 50 + 5 * (x - 100);
    }

    printf("f(%d) = %.2f\n", x, y);

    return 0;
}
```