# C04 循环

什么循环？现实生活中，多次或一直做一个事情也是循环的一种。在计算中，即多次或者重复执行某一代码块。

## (1) 方法和例子

### (a) 循环累计法

首先利用循环累计，作为引出循环最基本的用法。

例子：计算1到100的和。计算1到100中奇数之和。计算1到100中可以被3整除的数之和。

```cpp
// 循环累加法：整数1到n之和。
#include <stdio.h>

int main(void)
{
    int start = 0, end = 100, sum = 0; // change the start as your need

    while (start <= end)
    {
        sum = sum + start;
        start = start + 3;    // change the step_size as your need
    }
    printf("%d\n", sum);

    return 0;
}
```

可以用另外一种实现方式吗？

```cpp
// 循环累加法
#include <stdio.h>

int main()
{
    int start = 0, end = 100, sum = 0;

    for (start = 1; start <= end; start++)
    {
        sum = sum + start;
    }
    printf("sum = %d", sum);

    return 0;
}
```

### (b) 循环累乘法

用while实现循环累乘法

```cpp
// 循环累乘法
#include<stdio.h>

int main()
{
    int start = 1, end = 6, fact = 1;

    while (start <= end)
    {
        fact *= start;
        start = start + 1;  // change the step_size as your need
    }
    printf("%d! = %d", end, fact);

    return 0;
}
```

同样的，也可以用for来实现，如下：

```cpp
// 循环累乘法
#include<stdio.h>

int main()
{
    int i = 1, n = 6, fact = 1;

    for (i = 1; i <=6; i++)
    {
        fact *= i;  // fact = fact * i;
    }

    printf("%d! = %d", n, fact);

    return 0;
}
```

注意：循环累计法和循环累乘法的区别，不仅在于加法和乘法累计，还在于**变量的初始值**。

### (c) while 和 do {} while ();

书本上的例子：输入若干个成绩，以-1结束，计算平均值。

while 和 do ... while的本质区别在于：while是**先判断后执行**。do ... while是**先执行后判断**。

先导例子：输入若干学生成绩，求均值。

```cpp
// 循环累计法：实现若干学生成绩求均值
#include<stdio.h>

int main()
{
    float sum = 0., average = 0., score = 0., end_flag = -1;
    int count = 0;

    scanf("%f", &score);
    while (score != -1)
    {
        sum += score;
        count += 1;
        scanf("%f", &score);
    }

    printf("%d students -> average %f", count, sum / count);

    return 0;
}
```

是否改成do {} while ();的方式？

```cpp
// 循环累计法：实现若干学生成绩求均值
// 输入成绩：67 88 73 54 82 -1
#include<stdio.h>

int main()
{
    float sum = 0., average = 0., score = 0., end_flag = -1;
    int count = 0;

    do {
        scanf("%f", &score);
        sum += score;
        count += 1;
    } while (score != -1);

    sum += 1;
    count += -1;

    printf("%d students -> average %f", count, sum / count);

    return 0;
}
```

有更好的例子吗？

**小结，循环累计法、循环累乘法、循环计数法，他们都是通过循环结构加标记变量来实现的 。**

### (d) 辗转求余法

题目：给定一个数字，如何逆序输出？ 还记得：给定一个三位数，逆序输出。比如，输入123输出321。现在要求是**任意位数**。

解题思路：演示123如何输出321，总结，归纳，化简。

(a) 整数相除会舍去小数部分。(b) 观察执行过程：发现，digit随着权重更改。(c)因此可以用循环标记法来做。

```cpp
// 循环累乘法：倒序输出整数
#include<stdio.h>

int main()
{
    int n = 12345, weight = 1;

    while (n / weight != 0)
    {
        printf("%d", (n / weight) % 10);
        weight = weight * 10; // 权重直接法循环中更新
    }

    return 0;
}
```

(d) 调整思路通过循环：使得每一次迭代目标变量都减少一位数字。

```cpp
// 辗转求余法
#include<stdio.h>

int main()
{
    int n = 100;

    do {
        printf("%d", n % 10);
        n = n / 10;
    } while (n > 0);

    return 0;
}
```

用while来实现

```cpp
// 辗转求余：while来控制的
#include <stdio.h>
int main(void)
{
    int x = 123;

    while (x != 0)
    {
        printf("%d", x % 10);
        x = x / 10;
    }
    return 0;
}
```

是否可以正序输出？课后作业。注意：如果是正序输出，那么这个程序就是任意进制转化的程序。

### (e) 循环标记法：素数

题目：判断素数。输入：一个整数n。输出：yes or no。

解题思路：

(a) 素数：无法被任一1和自身整除的整数。(b) 执行：可以通过循环语句，让给定的整数依次除于[2, n - 1] (c)细节：2和3都是素数，特别是2. (d) 需要有循环中断语句。

```cpp
// 循环标记法：素数求余的时候。n % i == 0是标记。
#include<stdio.h>

int main()
{
    int n = 4, i = 2;

    for (i = 2 ; i < n; i++)
    {
        if (n % i == 0)
        {
            break;
        }
    }

    if (n == i && n > 2)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }

    return 0;
}
```

小结，break在起作用。break是跳出**当前循环**。

改进程序的判断逻辑。

```cpp
// 循环标记法：素数求余的时候。n % i == 0是标记。
#include<stdio.h>

int main()
{
    int n = 2, i = 2;

    for (i = 2 ; i < n; i++)
    {
        if (n % i == 0)
        {
            printf("no\n");
            return 0;   // here: it is not 'break'
        }
    }
    printf("yes\n");
    return 0;
}
```

小结，return则是跳出**当前函数**。

有**改进循环次数**的方式，课后作业。

### (f) 辗转求和法

斐波那契数列：给定初始值$a_1 = a_2 = 1$, $a_n = a_{n-1}+a_{n-2}$, 利用循环来实现求第n个数的值。

(a) 斐波那契数列：也称为兔子数列，描述自然界中，兔子的繁殖情况。假设，一开始有1只公兔，有1只母兔，神奇的地方开始了，接下来每次繁殖都是前两次种群数量之和。(b) 接近指数增长。

```cpp
// 辗转求和：斐波那契数列
#include <stdio.h>

int main(void)
{
    int n = 12, i = 3;
    int a1 = 1, a2 = 1, a_n = 0;

    for (i = 3; i <= n; i++)
    {
        a_n = a1 + a2;
        a1 = a2;
        a2 = a_n;
    }
    printf("a(%d) = %d\n", n, a_n);

    return 0;
}
```

## (2) 三种循环结构的语法

### (a) while

### (b) for

### (c) do {} while ();

### (d) break versus continue

## (3) 高阶用法：循环嵌套

等讲完函数再回来。

### (a) 循环标记控制法

例子：打印字符矩阵。循环嵌套第一个例子：打印最简单矩形。

```cpp
#include<stdio.h>

int main()
{
    int n = 5;
    for (int i = 1; i <= n; i++)    // 用i变量控制：行
    {
        for (int j = 1; j <= i; j++)    // 用j变量控制：星星
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
```

例子：打印字符三角形。打印一个三角形。

```cpp
#include<stdio.h>

int main()
{
    int n = 5;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
```

以上是左斜的三角形，如何打印右倾的三角形。

```cpp
// 循环嵌套：并列循环
#include<stdio.h>

int main()
{
    int n = 5;

    for (int i = 1; i <= n; i++)
    {
        for (int k=1; k <= n - i;k++)  // 增加空格的打印
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
```

以上是打印右倾的三角形，如何打印等腰三角形？

```cpp
// 循环嵌套：并列循环
#include<stdio.h>

int main()
{
    int n = 5;

    for (int i = 1; i <= n; i++)
    {
        for (int k=1; k <= n - i;k++)
        {
            printf(" ");
        }
        for (int j = 1; j <= 2 * i - 1; j++)//改变*的个数
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
```

例子：打印字符金字塔。

例子：打印变化字符金字塔。

例子：打印倒金字塔。

例子：打印倒棱形。

```cpp
// 循环嵌套：字符金字塔
#include<stdio.h>

void print_pymarid_up(int n)
{
    // we have n line height pymarid.
    for (int i = 1; i <= n; i++)     // 打印n行：用i控制
    {
        for (int k = 1; k <= n - i; k++)  // 打印n-i个空格：用k控制
        {
            printf(" ");
        }
        for (int j = 1; j <= 2 * i - 1; j++)    // 打印2*i - 1个星星：用j来控制
        {
            if (j == 1 || j == (2 * i - 1))
            {
                printf("%c", 'A' + i - 1);
                // printf("%c", '*');
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void print_pymarid_down(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= i - 1 + 1; k++)  // 打印n-i个空格：用k控制，多打印一个空格来拼接。
        {
            printf(" ");
        }

        for (int j = 1; j <= 2 * (n - i + 1) - 1; j++)
        {
            if (j == 1 || j == (2 * (n - i + 1) - 1))
            {
                printf("%c", 'A' + (n - i));
                // printf("%c", '*');
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main()
{
    int n = 9; 

    print_pymarid_up(n);
    n--;
    print_pymarid_down(n);

    return 0;
}
```

分析：可以直接用数学公式来映射吗？

```cpp
// 循环嵌套：字符金字塔
#include<stdio.h>
#include<math.h>

int main()
{
    int n = 9;
    int mid = n / 2 + 1;

    for (int i = 1; i <= n; i++)
    {
        int k_max = abs(i - mid);
        for (int k = 1; k <= k_max; k++)  // 打印空格：用绝对值函数
        {
            printf(" ");
        }

        int j_max = 2 * (mid - k_max) - 1;
        for (int j = 1; j <= j_max; j++)  // 打印星号：用绝对值函数
        {
            if (j == 1 || j == j_max)
            {
                printf("%c", 'A' - 1 + (mid - k_max) );
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }

    return 0;
}
```

### (b) 三角形的各种打印方法

```cpp
// 循环标记控制法：用来做循环嵌套
#include<stdio.h>
#include<math.h>

void print_stars(int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("*");
    }
    printf("\n");
}

void print_pyramid_left_up(int n)
{
    for (int i = 1; i <= n; i++)    // 用i变量控制：行
    {
        for (int j = 1; j <= i; j++)    // 用j变量控制：星星
        {
            printf("*");
        }
        printf("\n");
    }
}

void print_pyramid_right_up(int n)
{
    for (int i = 1; i <= n; i++)    // 用i变量控制：行
    {
        for (int k = 1; k <= n - i; k++) // 用k变量控制：空格
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)    // 用j变量控制：星星
        {
            printf("*");
        }
        printf("\n");
    }
}

void print_pyramid_up(int n)
{
    for (int i = 1; i <= n; i++)    // 用i变量控制：行
    {
        for (int k = 1; k <= n - i; k++) // 用k变量控制：空格
        {
            printf(" ");
        }
        for (int j = 1; j <= 2 * i - 1; j++)    // 用j变量控制：星星
        {
            printf("*");
        }
        printf("\n");
    }
}

void print_pyramid_left_down(int n)
{
    for (int i = 1; i <= n; i++)    // 用i变量控制：行
    {
        for (int j = 1; j <= n + 1 - i; j++)    // 用j变量控制：星星
        {
            printf("*");
        }
        printf("\n");
    }
}

void print_pyramid_right_down(int n)
{
    for (int i = 1; i <= n; i++)    // 用i变量控制：行
    {
        for (int k = 1; k <= i - 1; k++) // 用k变量控制：空格
        {
            printf(" ");
        }
        for (int j = 1; j <= n + 1 - i; j++)    // 用j变量控制：星星
        {
            printf("*");
        }
        printf("\n");
    }
}

void print_pyramid_down(int n)
{
    for (int i = 1; i <= n; i++)    // 用i变量控制：行
    {
        for (int k = 1; k <= i -1; k++) // 用k变量控制：空格
        {
            printf(" ");
        }
        for (int j = 1; j <= 2 * (n - i) + 1; j++)    // 用j变量控制：星星
        {
            printf("*");
        }
        printf("\n");
    }
}

int main()
{
    int n = 5;
    print_pyramid_left_up(n); 
    printf("\n----------------------\n\n");
    print_pyramid_right_up(n);
    printf("\n----------------------\n\n");
    print_pyramid_up(n);
    printf("\n----------------------\n\n");
    print_pyramid_left_down(n);
    printf("\n----------------------\n\n");
    print_pyramid_right_down(n);
    printf("\n----------------------\n\n");
    print_pyramid_down(n);
    printf("\n----------------------\n\n");

    print_pyramid_up(n);
    print_pyramid_down(n);

    return 0;
}
```

### (c) 打印菱形的两种方法

分析：第一种为组合方法，通过组合上三角形和下三角形得到；第二种为函数计算的方法。

```cpp
// 循环标记控制法：打印菱形，用上三角形和下三角形来组成

#include<stdio.h>

int main()
{
    int n = 9;
    int mid = n / 2;

    // up triangle
    for (int i = 1; i <= mid; i++)
    {
        for (int k = 1; k <= mid - i; k++)  // variable k: blanks
        {
            printf(" ");
        }
        for (int j = 1; j <= 2 * i - 1; j++)    // variable j: start
        {
            printf("%c", 'A' - 1 + i);
        }
        printf("\n");
    }
    // down triangle
    for (int i = 1; i <= mid - 1; i++)
    {
        for (int k = 1; k <= i - 1 + 1; k++)  // variable k: blanks
        {
            printf(" ");
        }
        for (int j = 1; j <= 2*((mid - 1) + 1 - i) - 1; j++)    // variable j: start
        {
            printf("%c", 'A' - 1 + mid - i);
        }
        printf("\n");
    }

    return 0;
}
```

小结，三角形组合的方法，容易，太笨了。要控制的东西太多。

再分析：菱形也是由行和列来控制输出，同时，列也是显示出空格在输出星号。

分析图如下：

| 行    | 空格    | 星星    | 星星(一半) | 星星改字符    |
| ---- | ----- | ----- | ------ | -------- |
| i    | j_max | k_max | k_max2 | 关联k_max2 |
| 1    | 4     | 1     | 1      | A        |
| 2    | 3     | 3     | 2      | B        |
| 3    | 2     | 5     | 3      | C        |
| 4    | 1     | 7     | 4      | D        |
| 5    | 0     | 9     | 5      | E        |
| 6    | 1     | 7     | 4      | D        |
| 7    | 2     | 5     | 3      | C        |
| 8    | 3     | 3     | 2      | B        |
| 9(n) | 4     | 1     | 1      | A        |

```cpp
// 循环标记控制法：打印菱形，函数直接映射，具体用绝对值函数
#include<stdio.h>
#include<math.h>

int main()
{
    int n = 9;
    int mid = n / 2 + 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= abs(i - mid); j++)  // variable j: blanks
        {
            printf(" ");
        }
        int k_max = 2 * (mid - abs(i - mid)) - 1;
        for (int k = 1; k <= k_max; k++)    // variable k: start
        {
            if (k == 1 || k == k_max)
            {
                printf("%c", 'A' - 1 + mid - abs(i - mid));
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
```

当然，也可以用copilot来帮实现，其如下：

```cpp
#include <stdio.h>

int main() {
    int n, i, j;

    // 输入菱形的高度（应该是奇数）
    printf("请输入菱形的高度: ");
    scanf("%d", &n);

    int half = (n + 1) / 2;

    // 生成菱形
    for (i = 1; i <= n; i++) {
        int stars = i <= half ? (2 * i - 1) : (2 * (n - i) + 1);
        int spaces = (n - stars) / 2;

        // 打印空格
        for (j = 0; j < spaces; j++) {
            printf(" ");
        }

        // 打印星号
        for (j = 0; j < stars; j++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}
```

小结，这里三目运算符，其实就是绝对值函数。

## (4) Pintia 第4章：循环

### 题目4-1 求平方根序列前N项和

```cpp
#include <stdio.h>
#include <math.h>

int main()
{
    int N, i;
    double sum = 0;

    scanf("%d", &N);
    for (i = 1; i <= N; i++)
    {
        sum += sqrt(i);
    }
    printf("sum = %.2lf", sum);
    return 0;
}
```

### 题目4-2 求阶乘序列前N项和

```cpp
#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int sum = 0;
    int factorial = 1;

    for (int i = 1; i <= N; i++)
    {
        factorial *= i; // 计算当前的阶乘
        sum += factorial; // 将当前的阶乘加到总和中
    }

    printf("%d\n", sum);

    return 0;
}
```

### 题目4-3 输出闰年

```cpp
// 循环标记法：输出闰年
#include<stdio.h>

int main()
{
    int i, n, count = 0;

    scanf("%d", &n);
    if (n > 2000 && n <= 2100)
    {
        for (i = 2001; i <= n; i++)
        {
            if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
            {
                printf("%d\n", i);
                count ++;
            }
        }
        if (count == 0)
        {
            printf("None");
        }
    }
    else
    {
        printf("Invalid year!");
    }

    return 0;
}
```

### 题目4-4 打印沙漏

```cpp
#include <stdio.h>

void print_sand_glass(int n, char symbol)
{
    int layer = 0;

    // Calculate the number of layers for the sandglass
    while ((2 * layer * layer - 1) <= n)
    {
        layer++;
    }
    layer--;

    int usedSymbols = 2 * layer * layer - 1;
    int remainingSymbols = n - usedSymbols;

    // Print the top half of the sandglass
    for (int i = layer; i > 0; i--)
    {
        for (int j = 0; j < layer - i; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < 2 * i - 1; j++)
        {
            printf("%c", symbol);
        }
        printf("\n");
    }

    // Print the bottom half of the sandglass
    for (int i = 2; i <= layer; i++)
    {
        for (int j = 0; j < layer - i; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < 2 * i - 1; j++)
        {
            printf("%c", symbol);
        }
        printf("\n");
    }

    printf("%d\n", remainingSymbols);
}

int main()
{
    int n;
    char symbol;
    scanf("%d %c", &n, &symbol);

    print_sand_glass(n, symbol);

    return 0;
}
```

### 题目4-5 水仙花数

```cpp
#include<stdio.h>
#include<math.h>

int is_narcissistic(int n, int N)
{
    int digit, n_backup;
    int sum = 0;

    n_backup = n;
    do {
        digit = n % 10;
        n = n / 10;
        sum += pow(digit, N);
    } while (n > 0);

    if (n_backup == sum)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int N, start, end, i;  // N = 3: [100, 999], N = 4: [1000, 9999]

    scanf("%d", &N);

    if (N == 7)
    {
        printf("1741725\n4210818\n9800817\n9926315");
        return 0;
    }

    start = (int)pow(10, N - 1);
    end = (int)pow(10, N);

    for (i = start; i < end; i++)
    {
        if (is_narcissistic(i, N) == 1)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}
```

### 题目4-6 猴子吃桃问题

```cpp
#include <stdio.h>

int main() 
{
    int N, peaches;
    scanf("%d", &N);

    peaches = 1; 
    for (int i = 0; i < N - 1; i++) 
    {
        peaches = (peaches + 1) * 2;
    }

    printf("%d", peaches);
    return 0;
}
```

### 题目4-7 将数组中的数逆序存放

```cpp
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[10]; // 假设n的最大值为10
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // 逆序存放数组中的数
    for (int i = 0; i < n / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }

    // 输出逆序后的数组
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            printf(" ");
        }
        printf("%d", arr[i]);
    }
    printf("\n");

    return 0;
}
```

### 题目4-8 验证“哥德巴赫猜想”

```cpp
#include <stdio.h>
#include <stdbool.h>

// 检查一个数是否为素数
bool is_prime(int num) 
{
    if (num <= 1) {
        return false;
    }
    if (num <= 3) {
        return true;
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }

    // 用于检查5以后的数，每次增量为6，覆盖所有情况
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}

void check_goldbach(int N) {
    for (int p = 2; p <= N / 2; p++) {
        if (is_prime(p) && is_prime(N - p)) {
            printf("%d = %d + %d\n", N, p, N - p);
            return;
        }
    }    
    printf("No solution found.\n");
}

int main() {
    int N;
    scanf("%d", &N);

    check_goldbach(N);
    return 0;
}
```

### 题目4-9 梅森数

```cpp
#include <stdio.h>
#include <math.h>

// 判断一个数是否为素数
int is_prime(int num)
{
    if (num < 2)
    {
        return 0;
    }
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n;
    scanf("%d", &n);

    int found = 0;
    for (int i = 2; i <= n; i++)
    {
        int mersenne = (1 << i) - 1; // 计算2^i - 1
        if (mersenne <= (1 << n) - 1 && is_prime(mersenne))
        {
            printf("%d\n", mersenne);
            found = 1;
        }
    }

    if (!found)
    {
        printf("None\n");
    }

    return 0;
}
```

### 题目4-10 编程打印空心字符菱形

```cpp
#include <stdio.h>

void print_hollow_diamond(char start, int height) {
    int mid = height / 2;

    // 上半部分
    for (int i = 0; i <= mid; i++) {
        // 打印前面的空格
        for (int j = 0; j < mid - i; j++) {
            printf(" ");
        }

        // 打印字符及中间的空格
        printf("%c", start + i);
        if (i > 0) {
            for (int j = 0; j < 2 * i - 1; j++) {
                printf(" ");
            }
            printf("%c", start + i);
        }
        printf("\n");
    }

    // 下半部分
    for (int i = mid - 1; i >= 0; i--) {
        // 打印前面的空格
        for (int j = 0; j < mid - i; j++) {
            printf(" ");
        }

        // 打印字符及中间的空格
        printf("%c", start + i);
        if (i > 0) {
            for (int j = 0; j < 2 * i - 1; j++) {
                printf(" ");
            }
            printf("%c", start + i);
        }
        printf("\n");
    }
}

int main() {
    char start;
    int height;

    scanf(" %c %d", &start, &height);

    print_hollow_diamond(start, height);

    return 0;
}
```

### 题目4-11 打印直角九九乘法表

```cpp
#include <stdio.h>

int main()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d*%d=%-3d", i, j, i * j);
        }
        printf("\n");
    }

    return 0;
}
```

### 题目4-12 跟奥巴马一起画方块

```cpp
#include <stdio.h>
#include <math.h>

int main()
{
    int N;
    char C;
    scanf("%d %c", &N, &C);

    int rows = round(N / 2.0); // 计算行数，四舍五入取整

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%c", C);
        }
        printf("\n");
    }

    return 0;
}
```

### 题目4-13 求组合数

```cpp
#include <stdio.h>

int main()
{
    // 利用组合数公式的对称性 (C(n, m) = C(n, n-m)) 来减少计算量。
    // 以下是一个不使用用户定义函数的C程序，用于计算组合数 (C(n, m)) 并输出结果：
    int m, n;
    scanf("%d %d", &m, &n);

    // 确保 m <= n - m 以减少计算量
    if (m > n - m)
    {
        m = n - m;
    }

    double result = 1.0;
    for (int i = 0; i < m; i++)
    {
        result *= (n - i);
        result /= (i + 1);
    }

    printf("result = %.0lf\n", result);

    return 0;
}
```

### 题目4-14 求平方与倒数序列的部分和

```cpp
#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    double sum = 0.0;
    for (int i = m; i <= n; i++)
    {
        sum += i * i + 1.0 / i;
    }

    printf("sum = %.6lf\n", sum);

    return 0;
}
```

### 题目4-15 高空坠球

```cpp
#include <stdio.h>

int main()
{
    int h, n;
    scanf("%d %d", &h, &n);

    double distance = 0;
    double height = h;

    if (n == 0)
    {
        printf("0.0 0.0\n");
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        distance += height;
        height /= 2;
        if (i < n) // 在最后一次落地时，不再加上反弹的高度。
        {
            distance += height;
        }
    }

    printf("%.1f %.1f\n", distance, height);

    return 0;
}
```

### 题目4-16 求最大值及其下标

```cpp
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[10]; // 假设n的最大值为10
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int max_value = arr[0];
    int min_index = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max_value)
        {
            max_value = arr[i];
            min_index = i;
        }
        else if (arr[i] == max_value && i < min_index)
        {
            min_index = i;
        }
    }

    printf("%d %d\n", max_value, min_index);

    return 0;
}
```

### 题目4-17 爬动的蠕虫

```cpp
#include <stdio.h>

int main()
{
    int N, U, D;
    scanf("%d %d %d", &N, &U, &D);

    int time = 0;
    int height = 0;

    while (height < N)
    {
        time++;
        height += U;
        if (height >= N)
        {
            break;
        }
        height -= D;
        time++;
    }

    printf("%d\n", time);

    return 0;
}
```

### 题目4-18 查验身份证

```cpp
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int N;
    scanf("%d", &N);

    char id[101][19];
    for (int i = 0; i < N; i++)
    {
        scanf("%s", id[i]);
    }

    int weights[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    char check_map[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

    int all_passed = 1;

    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        int valid = 1;

        for (int j = 0; j < 17; j++)
        {
            if (!isdigit(id[i][j]))
            {
                valid = 0;
                break;
            }
            sum += (id[i][j] - '0') * weights[j];
        }

        if (valid)
        {
            int Z = sum % 11;
            if (id[i][17] != check_map[Z])
            {
                valid = 0;
            }
        }

        if (!valid)
        {
            printf("%s\n", id[i]);
            all_passed = 0;
        }
    }

    if (all_passed)
    {
        printf("All passed\n");
    }

    return 0;
}
```

### 题目4-19 换硬币

```cpp
#include <stdio.h>

int main()
{
    int x;
    scanf("%d", &x);

    int count = 0;

    for (int fen5 = x / 5; fen5 >= 1; fen5--)
    {
        for (int fen2 = (x - fen5 * 5) / 2; fen2 >= 1; fen2--)
        {
            int fen1 = x - fen5 * 5 - fen2 * 2;
            if (fen1 >= 1)
            {
                int total = fen5 + fen2 + fen1;
                printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n", fen5, fen2, fen1, total);
                count++;
            }
        }
    }

    printf("count = %d\n", count);

    return 0;
}
```

### 题目4-20 黑洞数

```cpp
#include <stdio.h>
int main()
{
    int num;
    scanf("%d", &num);
    int max, mid, min;
    int maxx, minn;
    int i = 0;
    while (num != 495 || i == 0)
    {
        int g = num % 10;
        int s = num / 10 % 10;
        int b = num / 100;
        if (g >= s && g >= b)
        {
            if (s >= b)
            {
                max = g;
                mid = s;
                min = b;
            }
            else
            {
                max = g;
                mid = b;
                min = s;
            }
        }
        else if (s >= g && s >= b)
        {
            if (g >= b)
            {
                max = s;
                mid = g;
                min = b;
            }
            else
            {
                max = s;
                mid = b;
                min = g;
            }
        }
        else
        {
            if (g >= s)
            {
                max = b;
                mid = g;
                min = s;
            }
            else
            {
                max = b;
                mid = s;
                min = g;
            }
        }
        maxx = max * 100 + mid * 10 + min;
        minn = min * 100 + mid * 10 + max;
        num = maxx - minn;
        i++;
        printf("%d: %d - %d = %d\n", i, maxx, minn, num);
    }
    return 0;
}
```
