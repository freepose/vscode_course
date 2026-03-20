
# C04 循环结构

## 1. 循环结构概述

循环结构是指在满足某个条件的情况下，重复执行一段代码的结构。C语言提供了三种循环结构：`for`循环、`while`循环和`do-while`循环。

## 2. 引入：对比if() 和 while()的对比

在C语言中，`if`语句和`while`循环都是用于控制程序流程的结构，但它们的用途和行为有所不同。
- `if`语句：用于根据条件执行一次代码块。如果条件为真，执行代码块；如果条件为假，跳过代码块。
```c
if (condition) {
    // 执行代码块
}
``` 
- `while`循环：用于在条件为真时重复执行代码块。只要条件为真，代码块就会被执行多次。
```c
while (condition) {
    // 执行代码块
}
```

## 3. for循环和while循环在功能上是等价的

`for`循环和`while`循环在功能上是等价的，它们都可以用来实现相同的循环逻辑。区别在于它们的语法结构和使用场景。

- `for`循环：通常用于已知循环次数的情况。它包含三个部分：初始化、条件判断和更新。
```c
for (initialization; condition; update) {
    // 执行代码块
}
```

- `while`循环：通常用于循环次数未知的情况。它只包含一个条件判断。
```c
while (condition) {
    // 执行代码块
}
```

## 4. 循环累计法：求1到100的和

```c
#include <stdio.h>

int main() 
{
    int sum = 0; // 初始化累加器
    for (int i = 1; i <= 100; i++) { // 循环从1到100
        sum += i; // 累加当前数值
    }
    printf("1到100的和是: %d\n", sum); // 输出结果
    return 0;
}
```

## 5. 循环累乘法：求1到6的阶乘

```c
#include <stdio.h>

int main() 
{
    int factorial = 1; // 初始化累乘器
    for (int i = 1; i <= 6; i++) { // 循环从1到6
        factorial *= i; // 累乘当前数值
    }
    printf("1到6的阶乘是: %d\n", factorial); // 输出结果
    return 0;
}
```

## 6. 循环标记法：判断素数

什么是素数？素数是指大于1的自然数，除了1和它本身外，不能被其他自然数整除的数。

``` cpp

// is prime number: 循环标记法

#include <stdio.h>

int main()
{
    int n = 6;

    int i;
    int is_prime = 1; // Assume n is prime

    scanf("%d", &n);

    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            is_prime = 0;
            break;
        }        
    }

    printf("%d is %s prime number.\n", n, is_prime ? "a" : "not a");

    return 0;
}
```