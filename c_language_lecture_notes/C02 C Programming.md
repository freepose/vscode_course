# C02 用C语言写程序

> 千里之行，始于足下。

需要注意的编程习惯：注意大小写，注意中英文，注意缩进，注意分号，注意换行。

成双成对，先主题后细节。

关键：遇到问题，关键是要懂得表达。

## (1) 若干例子

例2-1：在屏幕上显示一些信息

```cpp
// The "Hello, World!" program for c beginners.

#include<stdio.h>

int main()
{
    printf("Hello World!");
    return 0;
}
```

小结，介绍main函数，介绍printf函数，以及调用的头文件。

习惯：成双成对，注意缩进，填空式编程。

例2-3：求华氏温度100°F 对应的摄氏温度

```cpp
#include <stdio.h>

int main()
{
    /* 定义两个整型变量，celsius表示摄?度，fahr表示华?度 */
    int celsius, fahr;

    /* 空?，?于分隔变量定义和可执?语句 */
    fahr = 100;                    /* 对变量fahr 赋值*/
    celsius = 5 * (fahr - 32) / 9; /* 温度转换计算*/

    printf("fahr = %d, celsius = %d\n", fahr, celsius);

    return 0;
}
```

小结，介绍变量的数据类型。正式进入程序设计的三段式：声明，计算，输出。

例2-4：分段计算水费。

```cpp
// 分段函数介绍
#include <stdio.h>

int main(void)
{
    double x, y;

    printf("Enter x (x>=0):\n");
    scanf("%lf", &x);

    if (x <= 15)
    {
        y = 4 * x / 3;
    }
    else
    {
        y = 2.5 * (x - 15) + 20;
    }
    printf("y = f(%f) = %.2f\n", x, y);

    return 0;
}
```

小结，介绍scanf函数，以及if ... else...的用法。

## (2) Pintia

### 题目2-1 Hello World!

```cpp
#include<stdio.h>

int main()
{
    printf("Hello World!");
    return 0;
}
```

### 题目2-2 Say Hello to Integers

```cpp
#include <stdio.h>

int main() 
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("Hello, %d and %d!\n", a, b);
    return 0;
}
```

### 题目2-3 求圆周长

```cpp
#include <stdio.h>

int main() 
{
    float r;
    scanf("%f", &r);
    printf("s=%.6f\n", 2 * 3.14 * r);
    return 0;
}
```

### 题目2-4 表格输出

```cpp
#include <stdio.h>

int main() 
{
    printf("------------------------------------\n");
    printf("Province      Area(km2)   Pop.(10K)\n");
    printf("------------------------------------\n");
    printf("Anhui         139600.00   6461.00\n");
    printf("Beijing        16410.54   1180.70\n");
    printf("Chongqing      82400.00   3144.23\n");
    printf("Shanghai        6340.50   1360.26\n");
    printf("Zhejiang      101800.00   4894.00\n");
    printf("------------------------------------\n");

    return 0;
}
```

### 题目2-5 输出倒三角图案

```cpp
#include<stdio.h>
#include<math.h>

int main()
{
    printf("* * * *\n");
    printf(" * * *\n");
    printf("  * *\n");
    printf("   *\n");
    return 0;
}
```

### 题目2-6 逆序的三位数

解题思路：(1) 通过求余方式，可以对整数特定位数。(2) 整数除以10可以减去最后一位数。

```cpp
#include <stdio.h>

int main()
{
    int n, ge, shi, bai, r_n;

    scanf("%d", &n);

    ge = (n / 1) % 10;
    shi = (n / 10) % 10;
    bai = (n / 100) % 10;

    // recovery
    r_n = ge * 100 + shi * 10 + bai * 1;
    printf("%d", r_n);

    return 0;
}
```

### 题目2-7 混合类型数据格式化输入

```cpp
#include <stdio.h>

int main() 
{
    float float1, float2;
    int integer;
    char character;
    scanf("%f %d %c %f", &float1, &integer, &character, &float2);
    printf("%c %d %.2f %.2f\n", character, integer, float1, float2);

    return 0;
}
```

### 题目2-8 计算存款利息

```cpp
#include <stdio.h>

int main()
{
    double money, rate, year, interest;
    scanf("%lf %lf %lf", &money, &year, &rate);

    interest = money * pow((1 + rate), year) - money;
    printf("interest = %.2lf\n", interest);

    return 0;
}
```

### 题目2-9 日期格式化

```cpp
#include <stdio.h>

int main() 
{
    int month, day, year;
    char dash1, dash2;

    scanf("%d%c%d%c%d", &month, &dash1, &day, &dash2, &year);
    printf("%d-%02d-%02d\n", year, month, day);

    return 0;
}
```

### 题目2-10 计算火车运行时间

```cpp
int main()
{
    int starttime, endtime;
    scanf("%04d %04d", &starttime, &endtime);

    int startHour = starttime / 100;
    int startminutes = starttime % 100;
    int endHour = endtime / 100;
    int endminutes = endtime % 100;
    int hour, minute;
    if (endminutes - startminutes < 0)
    {
        hour = endHour - startHour - 1;
        minute = endminutes - startminutes + 60;
    }
    else
    {
        hour = endHour - startHour;
        minute = endminutes - startminutes;
    }
    printf("%02d:%02d\n", hour, minute);

    return 0;
}
```