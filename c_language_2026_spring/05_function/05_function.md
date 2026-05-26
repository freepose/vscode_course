
# C05 函数


从数学的角度来看，函数是一个输入和输出之间的关系，即$$y = f(x)$$

在C语言中，函数也是一个独立的代码块，可以被调用来执行特定的任务。

---

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

## 2. 函数的分类

从C语言的角度来看：
- 有主函数，也就是`main`函数，是程序的入口点。
- 库函数，如`printf`和`pow`，是由C标准库提供的函数，可以直接使用。
- 用户自定义函数三种类型的函数，是由程序员自己定义的函数，可以根据需要进行调用。

函数可以根据不同的标准进行分类：
- 根据是否有返回值：有返回值的函数和无返回值的函数。
- 根据参数的类型和数量：无参数函数、单参数函数、多参数函数。   
- 根据函数的作用域：全局函数和局部函数。

## 3. 函数的声明和定义

比如，我们可以先声明一个函数，然后在后面定义它：

```c
#include <stdio.h>

// 函数声明
int add(int a, int b);

int main()
{
    int x = 5, y = 10;
    printf("The sum of %d and %d is %d\n", x, y, add(x, y));
    return 0;
}

// 函数定义
int add(int a, int b)
{
    return a + b;
}
```
也可以直接定义函数而不进行声明：

```c

#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int main()
{
    int x = 5, y = 10;
    printf("The sum of %d and %d is %d\n", x, y, add(x, y));
    return 0;
}
```

### 3.1 函数的参数传递

从实参传递到形式参数的过程。其过程是值传递，即（变量的副本）赋值操作。补充个例子：

```c
#include <stdio.h>

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x = 5, y = 10;
    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(x, y);
    printf("After swap: x = %d, y = %d\n", x, y);
    return 0;
}
```

在这个例子中，`swap`函数试图交换`x`和`y`的值，但由于C语言中的参数传递是值传递，函数内部的修改不会影响到主函数中的变量。

### 3.2 函数的返回值

函数可以返回一个值，使用`return`语句来指定返回值。回到上面`add`函数的例子，我们可以看到它返回了两个整数的和，实际上是对返回值进行赋值操作。

```c

#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int main()
{
    int x = 5, y = 10;
    int z = add(x, y); // 将函数的返回值赋给变量z
    
    printf("The sum of %d and %d is %d\n", x, y, z);
    return 0;
}
```

注意到，返回值的类型必须与函数定义中的返回类型一致，否则会导致编译错误或运行时错误。同时，有`return`也只能返回一个值，如果需要返回多个值，可以使用结构体或者指针来实现。

## 4. 函数的递归

递归是指函数直接或间接调用自身的过程。递归函数包含：终止条件和递归式。
例如，
$$
f(n) = \begin{cases}
1, & \text{if } n = 0 \\
n \cdot f(n-1), & \text{if } n > 0
\end{cases}
$$

```c

#include <stdio.h>

int factorial(int n)
{
    if (n == 0)
    {
        return 1; // 终止条件
    }
    else
    {
        return n * factorial(n - 1); // 递归式
    }
}

int main()
{
    int n = 5;
    printf("Factorial of %d is %d\n", n, factorial(n));
    return 0;
}
```

### 4.1 递归的优缺点

递归的优点：
- 代码简洁，易于理解和维护。
- 适合解决一些自然递归的问题，如树的遍历、图的搜索等。

递归的缺点：
- 可能导致栈溢出，特别是当递归深度过大
- 可能效率较低，因为每次函数调用都会有一定的开销。
- 可能存在重复计算的问题，例如在斐波那契数列中，递归会导致大量的重复计算。

因此，在使用递归时，需要注意终止条件的设置，避免过深的递归调用，并且在某些情况下可以考虑使用迭代来替代递归，以提高效率。

### 4.2 递归进阶：汉诺塔

汉诺塔问题是一个经典的递归问题，要求将n个盘子从一个柱子移动到另一个柱子，且每次只能移动一个盘子，并且不能将大盘子放在小盘子上。

问题的形式化如下：
$$
H(n, A, B, C) = \begin{cases}
1, & \text{if } n = 1 \\
H(n-1, A, C, B) + 1 + H(n-1, B, A, C), & \text{if } n > 1
\end{cases}
$$
其中，$H(n, A, B, C)$表示将n个盘子从柱子A移动到柱子C，使用柱子B作为辅助。`+1`表示移动一个盘子。

```c
#include <stdio.h>

void hanoi(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", from, to);
    }
    else
    {
        hanoi(n - 1, from, aux, to); // 将n-1个盘子从from移动到aux
        printf("Move disk %d from %c to %c\n", n, from, to); // 将第n个盘子从from移动到to
        hanoi(n - 1, aux, to, from); // 将n-1个盘子从aux移动到to
    }
}

int main()
{
    int n = 3; // 盘子数量
    hanoi(n, 'A', 'B', 'C'); // 将n个盘子从柱子A移动到柱子B，使用柱子C作为辅助
    return 0;
}
``` 

### 4.3 递归进阶：打印9*9乘法表

```c   

#include <stdio.h>

void print_multiplication_table(int n)
{
    if (n == 1)
    {
        printf("1*1=1\n");
    }
    else
    {
        print_multiplication_table(n - 1); // 打印前n-1行的乘法表
        for (int i = 1; i <= n; i++)
        {
            printf("%d*%d=%d ", i, n, i * n); // 打印第n行的乘法表
        }
        printf("\n");
    }
}

int main()
{
    int n = 9; // 乘法表的大小
    print_multiplication_table(n); // 打印n*9的乘法表
    return 0;
}
```

## 5. 更好的理解递归过程

用数字分解的例子来辅助理解递归过程：

```c

// 递归函数：打印一个整数的每一位数字（从右到左）

#include <stdio.h>

void print_digits(int n)
{
    if (n < 10)
    {
        printf("%d ", n); // 打印最后一个数字
    }
    else
    {
        print_digits(n / 10); // 递归调用，处理前面的数字
        printf("%d ", n % 10); // 打印当前的最后一个数字
    }
}

int main()
{
    int n = 12345;
    print_digits(n);
    return 0;
}
```

``` c

// 递归函数：打印一个整数的每一位数字（从左到右）

void print_digits(int n)
{
    if (n < 10)
    {
        printf("%d ", n); // 打印最后一个数字
    }
    else
    {
        printf("%d ", n % 10); // 打印当前的最后一个数字
        print_digits(n / 10); // 递归调用，处理前面的数字
        
    }
}

int main()
{
    int n = 12345;
    print_digits(n);
    return 0;
}
```