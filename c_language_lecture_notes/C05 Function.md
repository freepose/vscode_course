# C05 函数-初阶

引导性的介绍函数？并引入函数的定义？函数声明、定义和使用。

## 1. 引导性的例子

从已知的事务，找到新的事情。也就是，太阳底下没有新鲜事。

printf是我们接触到第一个函数。在这之前，我们接触到数学意义上的函数。y <- f(x)。简单的理解，数学讲的是：映射，符号系统。而计算机讲的是：执行。本质区别：时间成本，存储和执行。

### (1) 函数的声明、定义和使用

函数分类：main()有且仅有一个，而且是程序入口；built-in，库函数，语言越强大库函数越强；用户定义函数，可以自己根据自己的业务规则自定。

举个例子，求圆柱体的体积和表面积。

```cpp
// 计算圆柱体：体积和表面积
#include <stdio.h>

float cyliner_volume(float r, float h)
{
    float pi = 3.14;
    return (pi * r * r) * h;
}

float cyliner_surface(float r, float h)
{
    float pi = 3.14;
    return 2 * (pi * r * r) + (2 * pi * r) * h;
}

int main()
{
    float radius = 2, height = 5;
    float pi = 3.14;
    float volume = 0., surface = 0.;

    volume = (pi * radius * radius) * height;
    surface = 2 * (pi * radius * radius) + (2 * pi * radius) * height;

    printf("volume = %.2f\nsurface = %.2f\n", volume, surface);

    printf("volume = %.2f\nsurface = %.2f\n",
        cyliner_volume(radius, height),
        cyliner_surface(radius, height));

    return 0;
}
```

小结，概念要学。调用要学。具体来说：函数名，形参，函数体，返回值。调用的时候：实参和形参。实参和形参的高级用法：见**交换两个数**的例子。

### (2) 判断素数

用函数写一个判断素数的函数。

```cpp
// 循环标记法：素数求余的时候。n % i == 0是标记。
#include<stdio.h>

int is_prime(int n)
{
    int i;
    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return 0;   // here: 0 denotes false;
        }
    }
    return 1;   // here: 0 denotes true;
}

int main()
{
    int n = 15;

    if (is_prime(n) == 1)
    {
        printf("%d is a prime number\n", n);
    }
    else
    {
        printf("%d is not a prime number\n", n);
    }

    return 0;
}
```

经过以上两个例子，我们问一个问题？函数化给我带来什么？同时请回忆，函数是C语言的最小单位。

正面回答：让编程变得可以管理。让大型系统的实现，变得可维护。函数的使用变得可复用，可集成。

### (3) 判断奇偶数

学习如何精简代码：简约不简单。

```cpp
#include<stdio.h>

int is_even(int n)
{
    return n % 2 == 0;
}

int main()
{
    printf("%s\n", is_even(5) ? "Yes" : "No");
    return 0;
}
```

### (4) 求100以内的全部素数

分析：循环比较法，从2遍历到100，遍历过程中用if语句判断是否是素数。格式化输出要求是：每行10个数字。输出只需要判断目前是第几个，可以被10整除即可换行。

```cpp
// 循环标记法：用函数封装素数判断函数，并循环调用。用了两次循环标记。
#include<stdio.h>
#include<math.h>

int is_prime(int m)
{
    int i, n;
    if (m == 1) 
    {
        return 0;
    }
    for (i = 2; i <= sqrt(m); i++)
    {
        if (m % i == 0) 
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int i, n = 100, counter = 0;

    for (i = 2; i <= n; i++)
    {
        if (is_prime(i))
        {
            counter++;
            printf("%d%s", i, (counter % 10 == 0 ? "\n" : "\t"));
        }
    }

    return 0;
}
```

### (5) Calculate Pi using Gregory method

通过epsilon控制精度，即控制循环条件。

```cpp
#include<stdio.h>
#include<math.h>

double estimate_pi(double epsilon)
{
    // 循环累计法
    double sum = 0., item = 1.;
    int sign = 1, n = 1;

    while (fabs(item) > epsilon)
    {
        sum += item;
        n += 1;
        sign *= -1;
        item = sign * 1. / (2 * n - 1);
    }

    return sum * 4;
}

int main()
{
    printf("pi = %.15lf\n", estimate_pi(10e-10));
    return 0;
}
```

通过改进通式中分子的迭代方法，得到如下：

```cpp
#include<stdio.h>
#include<math.h>

double estimate_pi(double epsilon)
{
    double sum = 0.0, item = 1.;
    int denumerator = 1, sign = 1;

    while (fabs(item) > epsilon)
    {
        sum += item;
        denumerator += 2;
        sign *= -1;
        item = sign * 1. / denumerator;
    }
    return 4 * sum;
}

int main()
{
    printf("pi = %.15lf\n", estimate_pi(10e-10));
    return 0;
}
```

### (6) 字符金字塔

分析：这是一个没有返回值的函数。我们之前所有函数都有，现在写一个没有返回值的函数。

### (7) 结构化编程

分析：程序设计范畴。这里先不展开。

## 2. 函数高阶用法

已经学过数组，指针，结构体，和结构体数组，以及如何传递这些变量给函数。接下来，学习如何使用递归函数。递归函数具有代码简洁，逻辑不好理解的特点。

### (1) 递归函数

讲解：这是函数的高阶用法。调用自身的方法。回归阶乘的例子，之前循环累乘法。现在可以阶乘的方式。在展开之前，可以尝试探索下，如何做。

```cpp
// Chapter 10: Functions to advance

// Example 10-0: Recall the previous example on factor calculation (i.e., n!)

#include<stdio.h>

double fact(int n)  
{
    // 递归过程中：函数压栈，对应的函数参数也被压栈，函数出战，对应的函数参数也被出栈，并给函数返回值。
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n * fact(n - 1);
}

int main()
{
    int n = 16;

    printf("%d! = %.0f\n", n, fact(n));

    return 0;
}
```

为了讲清楚阶乘的例子：需要具备这几个知识点，(a) 函数执行顺序，函数内的执行顺序和函数外的执行顺序。(b) 递归条件。(c) 递归过程，也就是函数的入栈、出栈过程。

```cpp
// Example 10-1: calculate the volume and surface area of a cylinder

// For this example, we are not talking about how to define and use function(s),
// but the workflow of the program. The excution is: 27 -> 13 -> 30 -> 19 -> 33

#include <stdio.h>

#define PI 3.14159

double cyliner_volume(double r, double h)
{
    printf("here is line 13\n");
    return PI * r * r * h;
}

double cyliner_surface(double r, double h)
{
    printf("here is line 19\n");
    return 2 * PI * r * (r + h);
}

int main()
{
    double r = 1.0, h = 1.0;

    printf("here is line 27\n");
    printf("Volume: %.2f\n", cyliner_volume(r, h));

    printf("here is line 30\n");
    printf("Surface: %.2f\n", cyliner_surface(r, h));

    printf("here is line 33\n");
    return 0;
}
```

调试：函数压栈。**执行的时候，函数入栈是带着参数，每一次入栈参数都被保存下来了。函数出栈的时候，函数和参数是被弹出来的**。

现在清楚函数的执行过程，请思考可以用递归实现把一个数字拆分成若干个整数，正序或逆序输出。

另外一个例子是：汉诺塔。有个问题规约。

```cpp
// Example 10-2: hanio tower

#include <stdio.h>

void hanio(int n, char a, char b, char c)
{
    if (n == 1)
    {
        printf("%c -> %c\n", a, b);
    }
    else 
    {
        hanio(n - 1, a, c, b);
        printf("%c -> %c\n", a, b);
        hanio(n - 1, c, b, a);
    }
}


int main()
{
    int n = 123;

    hanio(10, 'A', 'B', 'C');
    return 0;
}
```

### (2) 指针函数

讲解：这是函数的高阶用法。函数名作为参数传递。

## (3) Pintia第5章：函数

### 函数题6-1 简单阶乘计算

```cpp
int Factorial( const int N )
{
    int f = 1;

    if ( N < 0)
    {
        return 0;
    }

    for (int i = 2; i <= N; i++)
    {
        f *= i;
    }

    return f;

}
```

### 函数题6-2 判断奇偶性

```cpp
int even( int n )
{
    return n % 2 == 0;
}
```

### 函数题6-3 使用函数求素数和

```cpp
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
```

### 函数题6-4 使用函数输出指定范围内的完数

```cpp
// 计算整数的因子和
int factorsum(int number)
{
    int sum = 0;
    for (int i = 1; i <= number / 2; i++)
    {
        if (number % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}

// 输出给定范围内的所有完数
void PrintPN(int m, int n)
{
    int found = 0;
    for (int i = m; i <= n; i++)
    {
        if (factorsum(i) == i)
        {
            found = 1;
            printf("%d = 1", i);
            for (int j = 2; j <= i / 2; j++)
            {
                if (i % j == 0)
                {
                    printf(" + %d", j);
                }
            }
            printf("\n");
        }
    }
    if (!found)
    {
        printf("No perfect number\n");
    }
}
```

### 函数题6-5 使用函数输出指定范围内的Fibonacci数

```cpp
// 计算第n项Fibonacci数
int fib(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    int a = 1, b = 1, c;
    for (int i = 3; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

// 输出给定范围[m, n]内的所有Fibonacci数
void PrintFN(int m, int n)
{
    int a = 1, b = 1, c;
    int found = 0;

    if (a >= m && a <= n)
    {
        printf("%d", a);
        found = 1;
    }

    if (b >= m && b <= n)
    {
        if (found)
        {
            printf(" ");
        }
        printf("%d", b);
        found = 1;
    }

    while (1)
    {
        c = a + b;
        if (c > n)
        {
            break;
        }
        if (c >= m)
        {
            if (found)
            {
                printf(" ");
            }
            printf("%d", c);
            found = 1;
        }
        a = b;
        b = c;
    }

    if (!found)
    {
        printf("No Fibonacci number");
    }
    printf("\n");
}
```

### 函数题6-6 递归求阶乘和

```cpp
// 计算n的阶乘，使用递归实现
double fact(int n)
{
    if (n == 0 || n == 1)
    {
        return 1.0;
    }
    return n * fact(n - 1);
}

// 计算1! + 2! + ... + n! 的值
double factsum(int n)
{
    double sum = 0.0;
    for (int i = 1; i <= n; i++)
    {
        sum += fact(i);
    }
    return sum;
}
```

### 函数题6-7 递归求Fabonacci数列

```cpp
// 计算第n个Fibonacci数，使用递归实现
int f(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return f(n - 1) + f(n - 2);
}
```

### 函数题6-8 十进制转换二进制

```cpp
// 将非负整数n转换为二进制并输出，使用递归实现
void dectobin(int n)
{
    if (n > 1)
    {
        dectobin(n / 2);
    }
    printf("%d", n % 2);
}
```

### 函数题6-9 使用函数求最大公约数

```cpp
// 计算两个数的最大公约数，使用欧几里得算法
int gcd(int x, int y)
{
    if (y == 0)
    {
        return x;
    }
    return gcd(y, x % y);
}
```

### 函数题6-10 使用递归函数计算1到n之和

```cpp
// 计算1到n之和，使用递归实现
int sum(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    return n + sum(n - 1);
}
```

### 编程题略
