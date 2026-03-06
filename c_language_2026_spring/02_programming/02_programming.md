
# C02 顺序结构

## 1. 整型变量

整型变量是用来存储整数值的变量。在C语言中，整型变量可以存储正整数、负整数和零。常见的整型类型包括：
- `int`: 通常占用4字节，范围为-2,147,483,648到2,147,483,647
- `short`: 通常占用2字节，范围为-32,768到32,767
- `long`: 通常占用4或8字节，范围为-2,147,483,648到2,147,483,647（32位系统）或-9,223,372,036,854,775,808到9,223,372,036,854,775,807（64位系统）

```c
#include <stdio.h>

int main()
{
    int num_january;
    int num_february;
    int num_march;

    float num_average;

    printf("Enter the sales in January, February, and March: ");
    scanf("%d %d %d", &num_january, &num_february, &num_march);

    num_average = (num_january + num_february + num_march) / 3.0;
    printf("The average = %f\n", num_average);

    return 0;
}
```

## 2. 浮点型变量

浮点型变量是用来存储带有小数部分的数值的变量。在C语言中，常见的浮点类型包括：
- `float`: 通常占用4字节，精度约为7位小数
- `double`: 通常占用8字节，精度约为15位小数

```c
#include <stdio.h>

int main()
{
    float radius, circle_length, circle_area;

    printf("Radius = ");
    scanf("%f", &radius);

    circle_length = 2 * 3.14159 * radius;
    circle_area = 3.14159 * radius * radius;

    printf("Circle length = %.2f\n", circle_length);
    printf("Circle area = %.2f\n", circle_area);

    return 0;
}
```
## 3. 字符型变量

字符型变量是用来存储单个字符的变量。在C语言中，字符型变量使用`char`类型，通常占用1字节，可以存储ASCII码表中的字符。

```c

#include <stdio.h>

int main()
{
    char grade;

    printf("Enter your grade (A, B, C, D, F): ");
    scanf("%c", &grade);

    if (grade == 'A')
        printf("Excellent!\n");
    else if (grade == 'B')
        printf("Good!\n");
    else if (grade == 'C')
        printf("Fair!\n");
    else if (grade == 'D')
        printf("Poor!\n");
    else if (grade == 'F')
        printf("Fail!\n");
    else
        printf("Invalid grade!\n");

    return 0;
}
```