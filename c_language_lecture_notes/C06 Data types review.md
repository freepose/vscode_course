# C06 数据类型的回顾

开始：我们过去的编程学习中，学习了int, float, double, char，接下来我们要系统的学习数据类型。数据的类型不仅仅是**变量类型**，还包括**数据的存储类型**。举个例子：

```cpp
// 数据的类型简单示例
#include <stdio.h>

int main()
{
    int n1 = 123;   // 整数十进制123
    int n2 = 0123;  // 整数八进制0123

    printf("十进制数%d，对应的十进制数%d\n", n1, n1);
    printf("八进制数%o，对应的十进制数%d\n", n2, n2);

    // 输出
    //十进制数123，对应的十进制数123
    //八进制数123，对应的十进制数83
    return 0;
}
```

## (1) C语言中的变量类型有哪些？

变量类型：按照王老师的分类方法，包括**基础变量类型**和**组合变量类型**。例如，基础包括int, float, double, long, long double, char；组合变量类型，有数组，结构体，联合体。

### (a) 基础变量类型所占用的内存

```cpp
// 数据类型：基础数据类型
#include<stdio.h>

int main()
{
    short s1 = 5;
    int i1 = 5;
    long l1 = 5;
    unsigned int ui1 = 5;
    char ch1 = 'A'; // ASCII 表，256个符号，一个字节
    float f1 = 5;
    double d1 = 5;

    int* p1 = 0;
    double* p2 = 0;

    printf("short value %d has %d bytes.\n", s1, sizeof(s1));
    printf("int value %d has %d bytes.\n", s1, sizeof(i1));
    printf("long value %d has %d bytes.\n", s1, sizeof(l1));
    printf("unsigned int value %d has %d bytes.\n", s1, sizeof(ui1));
    printf("char value %c has %d bytes.\n", ch1, sizeof(ch1));
    printf("float value %f has %d bytes.\n", f1, sizeof(f1));
    printf("double value %lf has %d bytes.\n", d1, sizeof(d1));

    printf("pointer p1 value %p has %d bytes.\n", p1, sizeof(p1));
    printf("pointer p2 value %p has %d bytes.\n", p2, sizeof(p2));

    return 0;
}
```

### (b) 组合变量类型所占用的内存

## (2) C语言中的表达式有哪些？

按照王老师的分类有：单目运算符，双目运算符，三木运算符，以及位操作运算符。

```cpp
// 数据类型：运算符
#include<stdio.h>

int main()
{
    int n1 = -1;
    int n2 = +1;

    printf("%d %d\n", n1, n2);
    n1++;
    n2++;
    ++n1;
    ++n2;

    printf("%d %d\n", n1, n2);

    n1 = n1 << 2;
    printf("%d\n", n1);
    n1 = n1 >> 2;

    printf("%d\n", n1);

    n2 = 1 | 3;

    printf("%d\n", n2);

    return 0;
}
```

## (3) 原码、反码、补码

请思考：用原码的情况，存在正0和负0的情况？分析：负数的偏移一位，即可以多表达一个数字，这就是补码出发点。

```cpp
// 原码，反码，补码：数值溢出
#include <stdio.h>

int main()
{
    short sn1 = -32768;
    float pi = 3.141592653;

    sn1 -= 1;   // overstack：溢出
    printf("%d\n", sn1);

    printf("%.10f\n", pi);

    return 0;
}
```

## (4) 字符和数字之间的的转化

```cpp
// 字符就是数字：字符包括，字母，字符类型的数字。'A', '0'
#include <stdio.h>

int main()
{
    char ch1 = 'A';
    char ch2 = 'a';

    printf("letters: %c\t%c\n", ch1, ch2);
    printf("integers: %d\t%d\n", ch1, ch2);

    return 0;
}
```

```cpp
// 数据类型：字符和数字
#include<stdio.h>

int main()
{
    int n = 65;
    char ch = 'A';

    printf("%d -> %c\n", n, n);     // 65 -> A
    printf("%c -> %d\n", ch, ch);   // A -> 65

    // 比较大小：A-Za-z
    printf("%d -> %d\n", 'A', 'Z'); // 65 -> 90
    printf("%d -> %d\n", 'a', 'z'); // 97 -> 122

    return 0;
}
```

## (5) 大小写字符的转化

输入一行字符：转换该行字符的大小写字母，不改变其它字符。

分析：循环中标记，标记的是大写的字母和小写字母，并做位置偏移。

```cpp
// 数据类型：大小写转化
#include<stdio.h>

int main()
{
    char ch = 'A';

    printf("input characters: ");

    while ((ch = getchar()) != '\n') 
    {
        if ('A' <= ch && ch <= 'Z')
        {
            ch = ch - 'A' + 'a';
        }
        else if ('a' <= ch && ch <= 'z')
        {
            ch = ch - 'a' + 'A';
        }
        putchar(ch);
    }
    return 0;
}
```

## (6) 数字存储和显示

```cpp
// 数据表示
#include<stdio.h>

int main()
{
    int n1 = 122 + 1;   // 计算表示
    int n2 = 0173;      // 八进制数
    int n3 = 0x7B;      // 十六进制数
    long n4 = 123L;     // 长整型数
    unsigned int n5 = 123U;     

    float f1 = 123.0;   // 浮点数
    float f2 = 1.23e2;  // 科学计数法

    printf("%d\n", n1);
    printf("%d\n", n2);
    printf("%d\n", n3);
    printf("%d\n", n4);
    printf("%d\n", n5);

    printf("%f\n", f1);
    printf("%f\n", f2);

    return 0;
}
```

## (7) 转义字符

```cpp
// 转义字符：%%
#include<stdio.h>

int main()
{
    printf("%%%d", 50); // 转义字符

    return 0;
}
```

## (8) pintia第6章：变量类型回顾

### 题目6-1 温度转换

```cpp
#include <stdio.h>

int main()
{
    int fahr = 150;
    int celsius = 5 * (fahr - 32) / 9;

    printf("fahr = %d, celsius = %d\n", fahr, celsius);

    return 0;
}
```

### 题目6-2 将x的平方赋值给y

```cpp
#include <stdio.h>

int main()
{
    int x = 3;
    int y = x * x;

    printf("%d = %d * %d\n", y, x, x);
    printf("%d * %d = %d\n", x, x, y);

    return 0;
}
```

### 题目6-3 计算物体自由下落的距离

```cpp
#include <stdio.h>

int main()
{
    double g = 10.0; // 重力加速度，单位：米/秒^2
    double t = 3.0;  // 时间，单位：秒
    double distance = 0.5 * g * t * t; // 下落的垂直距离，单位：米

    printf("height = %.2f\n", distance);

    return 0;
}
```

### 题目6-4 厘米换算英尺英寸

```cpp
#include <stdio.h>

int main()
{
    int cm;
    scanf("%d", &cm);

    double total_inches = cm / 2.54; // 将厘米转换为总英寸数
    int feet = (int)(total_inches / 12); // 计算英尺数
    int inches = (int)(total_inches - feet * 12); // 计算剩余的英寸数

    printf("%d %d\n", feet, inches);

    return 0;
}
```

### 题目6-5 整数152的各位数字

```cpp
#include <stdio.h>

int main()
{
    int num = 152;
    int units = num % 10; // 个位数字
    int tens = (num / 10) % 10; // 十位数字
    int hundreds = num / 100; // 百位数字

    printf("%d = %d + %d*10 + %d*100\n", num, units, tens, hundreds);

    return 0;
}
```

### 题目6-6 计算存款利息

```cpp
#include <stdio.h>
#include <math.h>

int main()
{
    double money, year, rate, interest;

    scanf("%lf %lf %lf", &money, &year, &rate);

    interest = money * pow(1 + rate, year) - money;
    printf("interest = %.2f", interest);

    return 0;
}
```

### 题目6-7 后天

```cpp
#include <stdio.h>

int main()
{
    int D;
    scanf("%d", &D);

    int day_after_tomorrow = (D + 2) % 7;
    if (day_after_tomorrow == 0)
    {
        day_after_tomorrow = 7;
    }

    printf("%d\n", day_after_tomorrow);

    return 0;
}
```

### 题目6-8 是不是太胖了

```cpp
#include <stdio.h>

int main()
{
    int H;
    scanf("%d", &H);

    double standard_weight_kg = (H - 100) * 0.9; // 计算标准体重，单位：公斤
    double standard_weight_jin = standard_weight_kg * 2; // 将公斤转换为市斤

    printf("%.1f\n", standard_weight_jin);

    return 0;
}
```

### 题目6-9 混合类型数据格式化输入

```cpp
#include <stdio.h>

int main()
{
    float f1, f2;
    int i1;
    char ch1;

    scanf("%f %d %c %f", &f1, &i1, &ch1, &f2);
    printf("%c %d %.2f %.2f", ch1, i1, f1, f2);

    return 0;
}
```

### 题目6-10 BCD解密

```cpp
#include <stdio.h>

int main()
{
    int incorrect_decimal;
    scanf("%d", &incorrect_decimal);

    // 将错误的十进制数转换回十六进制表示的BCD数
    int bcd = incorrect_decimal;

    // 提取BCD数的高四位和低四位
    int high = (bcd >> 4) & 0xF;
    int low = bcd & 0xF;

    // 计算正确的十进制数
    int correct_decimal = high * 10 + low;

    printf("%d\n", correct_decimal);

    return 0;
}
```
