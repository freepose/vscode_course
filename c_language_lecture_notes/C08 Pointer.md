# C08 指针

指针即地址。-- 王智谨

## (1) 指针变量：指针类型的变量

讲解：指针类型的变量。用来存、取某个变量的地址。所有的指针都是4个字节（默认32位程序）。

```cpp
// 指针变量
#include <stdio.h>

int main()
{
    int* p = 0; // 指向整型数的指针变量
    int n = 10;

    int* p2 = &n; // 取地址运算符
    scanf("%d", p2);   
    printf("%d\n", *p2);     // 取内容运算符

    return 0;
}
```

可以调试这个过程吗？

```cpp
// 指针变量
#include <stdio.h>

int main()
{
    int n = 10;
    int* p = &n;

    printf("n的地址是：%p\n", p);
    scanf("%d", p);   
    printf("n的内容是：%d\n", *p);     // 取内容运算符

    return 0;
}
```

地址指向的内容被改变。则原来的变量值：直接被改变。

```cpp
// 指针变量
#include <stdio.h>

int main()
{
    int n = 10;
    int* p = &n;

    printf("n的地址是：%p\n", p);
    scanf("%d", p);   
    printf("n的内容是：%d\n", *p);     // 取内容运算符

    printf("%d", n);    // 内容被改变

    return 0;
}
```

## (2) 变量指针：交换两个数

### (a) 当指针变量遇到函数

引导：变量的指针，即指向某一个变量的指针。用指针实现交换两个数。

```cpp
// 当指针变量遇到函数：交换两个数
#include <stdio.h>

void swap(int *f, int *s)
{
    int t = *f;    // 改变的是指针所指向的内容
    *f = *s;
    *s = t;
}

int main()
{
    int a = 1, b = 2;

    printf("a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);

    return 0;
}
```

注意，传指针可以返回多个值。

```cpp
// 通过指针实现函数调用返回多个值
#include <stdio.h>

void month_day(int year, int yearday, int* pmonth, int* pday)
{
    // 输入年和天数，输出对应的年、月、日
    int k, leap;
    int tab[2][13] = {
        { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
        { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
    }; 

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    for (k = 1; yearday > tab[leap][k]; k++)
    {
        yearday -= tab[leap][k];
    }

    *pmonth = k;
    *pday = yearday;
}

int main(void)
{
    int day = 1, month = 1, year, yearday;

    printf("input year and yearday: ");
    scanf("%d%d", &year, &yearday);

    month_day(year, yearday, &month, &day);
    printf("%d-%d-%d \n", year, month, day);

    return 0;
}
```

### (b) 当指针遇到数组

引导：上述指针用来取和改（访问）变量。指针用来访问数组。指针如何访问数组？

```cpp
// 当指针变量遇到数组：用指针来访问数组
#include <stdio.h>

int main()
{
    int a[20] = {10, 6, 9, 1, 3, 5};
    int n = 6;
    int* p = 0;

    p = a;    // 数组名就是数组首地址

    for (int i = 0; i < n; i++)
    {
        //printf("%p -> a[%d] -> %d\n", &a[i], i, a[i]);
        //printf("%p -> a[%d] -> %d\n", p + i, i, *(p + i));
        printf("%p -> a[%d] -> %d\n", p, i, *p);
        p++;
    }

    return 0;
}
```

### (c) 传递一个数组给函数

引导：传递给函数的时候，一个参数传递一个变量，很难同传递几十或更多的变量。怎么解决？传递数组首地址，以及数组的长度。

```cpp
// 传递一个数组给函数
#include <stdio.h>

void print_array(int *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", p[i]);
    }
    printf("\n");
}

int main()
{
    int a[20] = {10, 6, 9, 1, 3, 5};
    int n = 6;

    print_array(a, n);
    a[2] = 200;
    print_array(a, n);

    // 裁剪数组
    print_array(&a[1], n - 1);

    return 0;
}
```

### (d) 冒泡排序

也叫金鱼排序。其核心思想：小的数在左边，大的数在右边，迭代。https://www.bilibili.com/video/BV181421876R/?vd_source=aff3cc6cdcf8ab37ab730a9cd777bc7a

```cpp
// 回顾选择排序，以及冒泡排序
#include <stdio.h>

void print_array(int *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("a[%d] -> %d\n", i, p[i]);
    }
}

void swap(int *px, int *py)
{
    int t = *px;
    *px = *py;
    *py = t;
}

void select_sort(int *p, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++) // 循环标记法：下标标记
        {
            if (p[min] > p[j])
            {
                min = j;
            }
        }

        if (min > i)
        {
            swap(&p[i], &p[min]);
        }
    }
}

void bubble_sort(int *p, int n)
{
    // 也叫金鱼排序。其核心思想：小的数在左边，大的数在右边，迭代。
    // 你们可以用循环标记控制法来尝试
    for (int i = 1; i < n; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - i; j++)
        {
            if (p[j] > p[j + 1])
            {
                swap(&p[j], &p[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)  // 标记法来标识：一次迭代中没有发生位置调整，则停止循环
        {
            break;
        }
    }
}

int main(void)
{
    int a[10] = {7, 3, 66, 3, -5, 22, -77, 2};
    int n = 8;

    print_array(a, n);
    // select_sort(a, n);
    bubble_sort(a, n - 2);
    print_array(a, n);

    return 0;
}
```

## (3) 指针数组

指针类型的数组。字符指针数组。

引导：奥运五环

```cpp
// Example 11-1:  奥运五环的颜色，可以用5个变量来表示

#include <stdio.h>

int main()
{
    char a1[] = "Blue";
    char a2[] = "Yellow";
    char a3[] = "Black";
    char a4[] = "Green";
    char a5[] = "Red";
    printf("The colors of the Olympic rings are: %s, %s, %s, %s, %s\n", a1, a2, a3, a4, a5);

    return 0;
}
```

小结，(a)重复一个类型的变量；(b) 不方便访问。这个问题，类似于之前'30个同学30个变量表示成绩'的问题。其实，只需要用一个变量就够，即字符串指针数组。一个简单粗暴的理解就是：

```cpp
// Example 11-1: 字符串指针数组来存储若干字符串，方便访问

#include <stdio.h>

int main()
{
    char* colors[5] = {"red", "green", "blue", "yellow", "black"};

    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", colors[i]);
    }

    return 0;
}
```

为了讲解字符指针数组，用排序5个颜色作为例子：

```cpp
// Example 11-1: 字符串指针数组来存储若干字符串，方便访问

#include <stdio.h>
#include <string.h>

typedef char * string;  // Note: string is a pointer to char

void print_colors(string colors[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", colors[i]);
    }
}

void sort_colors(string colors[], int n)
{
    // Bubble sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(colors[j], colors[j + 1]) > 0)
            {
                // swap colors[j] and colors[j + 1], they are pointers
                string temp = colors[j];
                colors[j] = colors[j + 1];
                colors[j + 1] = temp;
            }
        }
    }
}

int main()
{
    string colors[5] = {"red", "green", "blue", "yellow", "black"};

    // print_colors(colors, 5);
    sort_colors(colors, 5);
    print_colors(colors, 5);

    return 0;
}
```

小结，经过排序，我们改变colors的内容（指针），并不是改变colors所指向的内容。

## (4) 数组指针

数组类型的指针。引导：二级指针和多级指针。

```cpp
// Example 11-2: 指针的指针，指针的指针的指针

#include<stdio.h>

int main()
{
    int a = 10;
    int *pa = &a;
    int **ppa = &pa;    // 指针pa的指针
    int ***pppa = &ppa; // 指针ppa的指针

    printf("address = %p, a = %d\n", pa, a);
    printf("address = %p, *ppa = %x\n", ppa, *ppa);
    printf("address = %p, *pppa = %x\n", pppa, *pppa);

    // Where is a?
    printf("***pppa = %d, **ppa = %d, *pa = %d, a = %d\n", ***pppa, **ppa, *pa, a);

    return 0;
}
```

在例11-1中，通过字符串指针数组，存放5个字符串的地址。现在有一个新的问题：可以存储字符串本身吗？注意，字符串之间是不等长的。怎么做？

```cpp
// Example 11-4, 用二维数组存储字符串

#include <stdio.h>
#include <string.h>

void print_char2d(char colors2d[][7], int n)
{
    // The lower dimension sizes must be specified
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            printf("%c", colors2d[i][j]);
        }
        printf(" -> %d\n", strlen(colors2d[i]));
    }
}

int main()
{
    // Why need 7 to store the maximum of 6 characters?
    char colors2d[][7] = {{'r', 'e', 'd'},
                          {'g', 'r', 'e', 'e', 'n'},
                          {'b', 'l', 'u', 'e'},
                          {'y', 'e', 'l', 'l', 'o', 'w'},
                          {'b', 'l', 'a', 'c', 'k'}};

    print_char2d(colors2d, 5);

    return 0;
}
```

二维数组排序，特别是不等长数组：

```cpp
// Example 11-4, 用二维数组存储字符串

#include <stdio.h>
#include <string.h>

void print_char2d(char colors2d[][7], int n)
{
    // The lower dimension sizes must be specified
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            printf("%c", colors2d[i][j]);
        }
        printf(" -> %d\n", strlen(colors2d[i]));
    }
}

void swap(char *a, char *b, int n)
{
    for (int i = 0; i < n; i++)
    {
        char temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

void sort_color2d(char colors2d[][7], int n)
{
    // The lower dimension sizes must be specified
    // Bubble sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            //if (strcmp(colors2d[j], colors2d[j + 1]) > 0)
            if (strlen(colors2d[j]) > strlen(colors2d[j + 1]))
            {
                swap(colors2d[j], colors2d[j + 1], 7);
            }
            else if (strlen(colors2d[j]) == strlen(colors2d[j + 1]))
            {
                if (strcmp(colors2d[j], colors2d[j + 1]) > 0)
                {
                    // 如果长度相等，再比较字符串的大小
                    swap(colors2d[j], colors2d[j + 1], 7);
                }
            }
        }
    }
}

int main()
{
    // Why need 7 to store the maximum of 6 characters?
    char colors2d[][7] = {{'r', 'e', 'd'},
                          {'g', 'r', 'e', 'e', 'n'},
                          {'b', 'l', 'u', 'e'},
                          {'y', 'e', 'l', 'l', 'o', 'w'},
                          {'b', 'l', 'a', 'c', 'k'}};

    sort_color2d(colors2d, 5);
    print_char2d(colors2d, 5);

    return 0;
}
```

例11-5：指针数组的使用，汉字两个字节

```cpp
// Example 11-5, 藏头诗：类似五环的数组声明和定义

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *poem[4] = {"一叶轻舟向东流，", "帆梢轻握杨柳手，", "风纤碧波微起舞，", "顺水任从雅客悠。"};
    int n_sentences = sizeof(poem) / sizeof(poem[0]);

    // get first chinese character of each sentence
    char *buffer = (char *)malloc(n_sentences * sizeof(char) + 1);

    for (int i = 0; i < n_sentences; i++)
    {
        // buffer[2 * i + 0] = poem[i][0];
        // buffer[2 * i + 1] = poem[i][1];

        // memcpy(buffer + 2 * i, poem[i], 2);
        strncpy(buffer + 2 * i, poem[i], 2);
    }
    buffer[2 * n_sentences] = '\0';

    printf("%s\n", buffer);

    return 0;
}
```

## (5) 指针函数

 函数可以和指针一样：传递给函数。

## (6) 函数指针

## (7) pintia第8章：指针

### 题目8-1 在数组中查找指定元素

```cpp
#include <stdio.h>

int search(int *list, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (list[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int repeat;
    scanf("%d", &repeat);

    while (repeat--) {
        int n;
        scanf("%d", &n);

        int a[10];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        int x;
        scanf("%d", &x);

        int index = search(a, n, x);
        if (index != -1) {
            printf("index = %d\n", index);
        } else {
            printf("Not found\n");
        }
    }

    return 0;
}
```

### 题目8-2 输出学生成绩

```cpp
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    // 动态分配内存存储学生成绩
    int *scores = (int *)malloc(n * sizeof(int));
    if (scores == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // 读取学生成绩
    for (int i = 0; i < n; i++) {
        scanf("%d", &scores[i]);
    }

    // 计算平均成绩、最高成绩和最低成绩
    int sum = 0;
    int max = scores[0];
    int min = scores[0];
    for (int i = 0; i < n; i++) {
        sum += scores[i];
        if (scores[i] > max) {
            max = scores[i];
        }
        if (scores[i] < min) {
            min = scores[i];
        }
    }
    double average = (double)sum / n;

    // 输出结果
    printf("average = %.2f\n", average);
    printf("max = %.2f\n", (double)max);
    printf("min = %.2f\n", (double)min);

    // 释放动态分配的内存
    free(scores);

    return 0;
}
```

### 题目8-3 使用函数的选择法排序

```cpp
#include <stdio.h>

void sort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }
}

int main() {
    int repeat;
    scanf("%d", &repeat);

    while (repeat--) {
        int n;
        scanf("%d", &n);

        int a[10];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        sort(a, n);

        printf("After sorted:");
        for (int i = 0; i < n; i++) {
            printf(" %d", a[i]);
        }
        printf("\n");
    }

    return 0;
}
```

### 题目8-4 打印杨辉三角

```cpp
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int triangle[10][10] = {0};

    // 填充杨辉三角的值
    for (int i = 0; i < n; i++)
    {
        triangle[i][0] = 1;
        triangle[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
    }

    // 按照指定格式打印杨辉三角
    for (int i = 0; i < n; i++)
    {
        // 打印前导空格
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        // 打印杨辉三角的值
        for (int j = 0; j <= i; j++)
        {
            printf("%4d", triangle[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```

### 题目8-5 藏尾诗

```cpp
#include <stdio.h>
#include <string.h>

int main() 
{
    char line[28]; // 每行最多9个汉字，每个汉字3个字节，加上一个换行符和终止符
    char result[13]; // 最终结果最多4个汉字，每个汉字3个字节，加上终止符
    int resultIndex = 0;

    for (int i = 0; i < 4; i++) 
    {
        fgets(line, sizeof(line), stdin);
        int len = strlen(line);
        if (line[len - 1] == '\n') 
        {
            len--; // 去掉换行符
        }
        // 复制最后一个汉字到结果字符串：在UTF-8编码中，一个汉字占用3个字节。
        result[resultIndex++] = line[len - 3];
        result[resultIndex++] = line[len - 2];
        result[resultIndex++] = line[len - 1];
    }
    result[resultIndex] = '\0'; // 添加终止符

    printf("%s\n", result);

    return 0;
}
```

### 题目8-6 数列求和-加强版

```cpp
#include<stdio.h>
int main(void)
{
    // 数组存储结果：使用数组 sum 存储结果的每一位，避免大数溢出。
    // 进位处理：在每次乘法和加法操作后，处理进位，确保结果正确。
    // 逐步累加：通过逐步累加每一项，构建最终结果。
    int A,N;
    int a[100000]={0};
    int sum[110000]={0};
    long int i,j,k,len,tmp,carry;
    len=1;
    if(!scanf("%d %d",&A,&N))
        return -1;
    for(i=0;i<N;i++)
    {
        a[i]=A;
    }
    for(j=N,i=0;i<N&&j>0;i++,j--)
    {
        for(k=0;k<j;k++)
        {
            sum[i]=sum[i]+a[i];
        }
        tmp=sum[i];
        sum[i]=tmp%10;
        carry=tmp/10;
        len=i+1;
        while(carry>0)
        {
            carry=sum[len]+carry;
            sum[len]=carry%10;
            carry/=10;
            len++;
        }
    }
    for(i=len-1;i>=0;i--)
    {
        printf("%d",sum[i]);
    }
    return 0;
}
```

### 题目8-7 最长对称子串

```cpp
#include <stdio.h>
#include <string.h>

int longest_palindromic_substring(char *str) 
{
    int n = strlen(str);
    if (n == 0) return 0;

    int dp[1000][1000] = {0};
    int maxLength = 1;

    // 每个单个字符都是回文子串
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    // 检查两个字符的回文子串
    for (int i = 0; i < n - 1; i++) 
    {
        if (str[i] == str[i + 1]) 
        {
            dp[i][i + 1] = 1;
            maxLength = 2;
        }
    }

    // 检查长度大于2的回文子串
    for (int length = 3; length <= n; length++) 
    {
        for (int i = 0; i < n - length + 1; i++) 
        {
            int j = i + length - 1;
            if (str[i] == str[j] && dp[i + 1][j - 1]) 
            {
                dp[i][j] = 1;
                maxLength = length;
            }
        }
    }

    return maxLength;
}

int main() 
{
    char str[1001];
    fgets(str, 1001, stdin);

    // 去掉换行符
    str[strcspn(str, "\n")] = '\0';

    int result = longest_palindromic_substring(str);
    printf("%d\n", result);

    return 0;
}
```