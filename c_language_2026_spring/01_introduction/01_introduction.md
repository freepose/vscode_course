

# C01 C语言入门

## 1. 良好的编程习惯

良好的命名习惯

Windows C编程风格

保持缩进

## 2. 紧跟时代的编程方式

Vibe coding

Spec coding

## 3. 代码示例

```c
// Example 1-1: Say 'Hello, World!' in C
#include <stdio.h>

int main()
{
    printf("Hello, World!\n");
    return 0;
}
``` 

## 4. 和计算交互：比较用户输入的两个数字大小

```c

#include <stdio.h>

int main()
{
    int first, second, sum;

    printf("Enter the first number: ");
    scanf("%d %d", &first, &second);

    if (first > second)
    {
        printf("The larger number is: %d\n", first);
    }
    else if (first == second)
    {
        printf("Both numbers are equal.\n");
    }
    else
    { 
        printf("The larger number is: %d\n", second);
    }

    return 0;
}
```

## 5. 代码示例：计算两个数的和

```c
#include <stdio.h>

int main()
{
    int first, second, sum;

    printf("Enter the first number: ");
    scanf("%d", &first);

    printf("Enter the second number: ");
    scanf("%d", &second);

    sum = first + second;

    printf("The sum of %d and %d is: %d\n", first, second, sum);

    return 0;
}
```

## 6. 小结

程序结构有三种：顺序，选择，循环。

顺序结构：代码从上到下依次执行。