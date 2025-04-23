# C03 分支结构

## (1) 四种分支结构

    分支结构有四种。

### (a) 单分支结构

置零问题。

```cpp
#include<stdio.h>

int main()
{
    float volume = -1;    // 用水量

    scanf("%f", &volume);
    if (volume < 0)
    {
        volume = 0;
    }
    printf("water consumption is %.2f (ton)", volume);

    return 0;
}
```

### (b) 双分支结构

交水费。

```cpp
#include<stdio.h>

int main()
{
    float volume = -1, charge = 0.;    // 用水量

    scanf("%f", &volume);
    if (volume < 0)
    {
        volume = 0;
        charge = 0;
    }
    else // volume >= 0
    {
        charge = 3 * volume;
    }
    printf("%.2f (ton) -> %.2f (rmb)", volume, charge);

    return 0;
}
```

### (c) 多分支结构

阶梯水费

```cpp
#include<stdio.h>

int main()
{
    float volume = -1, charge = 0.;    // 用水量

    scanf("%f", &volume);
    if (volume < 0)
    {
        volume = 0;
        charge = 0;
    }
    else if (volume < 20) 
    {
        charge = 3 * volume; 
    }
    else if (volume < 30) 
    {
        charge = (volume - 20) * 3.5 + 20 * 3;  // 3.5v - 10
    }
    else if (volume < 50) 
    {
        charge = (volume - 30) * 4.5 + 10 * 3.5 + 20 * 3; 
    }
    else if (volume < 60) 
    {
        charge = (volume - 50) * 5.5 + 20 * 4.5 + 10 * 3.5 + 20 * 3;
    }
    else
    {
        printf("too much consumption! 去税务局");
    }

    printf("%.2f (ton) -> %.2f (rmb)", volume, charge);

    return 0;
}
```

```cpp
// 3-1 成绩转换
// 计算五分制成绩
#include<stdio.h>

int main()
{
    float score = 0.;    

    scanf("%f", &score);
    if (score >= 90)
    {
        printf("A");
    }
    else if (score >= 80)
    {
        printf("B");
    }
    else if (score >= 70)
    {
        printf("C");
    }
    else if (score >= 60)
    {
        printf("D");
    }
    else
    {
        printf("E");
    }

    return 0;
}
```

### (d) 开关语句

开关语句是由switch来实现：配合其他语句。难点是**case 配合 break**。

```cpp
// 分数转五等级
#include<stdio.h>

int main()
{
    int score = 0.;

    scanf("%d", &score);
    switch (score / 10)
    {
    case 10:
    case 9: printf("A"); break;
    case 8: printf("B"); break;
    case 7: printf("C"); break;
    case 6: printf("D"); break;
    case 5: 
    case 4: 
    case 3: 
    case 2: 
    case 1: 
    case 0: printf("E"); break;
    default: printf("Wrong score\n"); break;
    }

    return 0;
}
```

## (2) Pinta

### 题目3-1 成绩转换

```cpp
#include<stdio.h>

int main()
{
    float score = 0.;    // 用水量

    scanf("%f", &score);
    if (score >= 90)
    {
        printf("A");
    }
    else if (score >= 80)
    {
        printf("B");
    }
    else if (score >= 70)
    {
        printf("C");
    }
    else if (score >= 60)
    {
        printf("D");
    }
    else
    {
        printf("E");
    }

    return 0;
}
```

### 题目3-2 计算分段函数[2]

```cpp
#include <stdio.h>
#include <math.h>

int main()
{
    float x, y;

    scanf("%f", &x);
    printf("f(%.2f) = %.2f", x, (x >= 0 ? pow(x, 0.5) : pow(x + 1, 2) + 2 * x + 1. / x)); 

    return 0;
}
```

### 题目3-3 计算符号函数的值

```cpp
#include <stdio.h>

int main()
{
    int n;
    int y;
    scanf("%d", &n);
    if (n < 0)
    {
        y = -1;
    }
    else if (n == 0)
    {
        y = 0;
    }
    else
    {
        y = 1;    
    }

    printf("sign(%d) = %d", n, y);

    return 0;
}
```

### 题目3-4 用天平找小球

```cpp
#include <stdio.h>

int main()
{
    int a, b, c;
    int y;
    scanf("%d %d %d", &a, &b, &c);
    if (a == b)
    {
        printf("C");
    }
    else if (b == c)
    {
        printf("A");
    }
    else
    {
        printf("B");
    }

    return 0;
}
```

### 题目3-5 输出三角形面积和周长

```cpp
#include <stdio.h>
```

### 题目3-6 计算油费

### 题目3-7 三天打鱼两天晒网

### 题目3-8 三个数由小到大输出

### 题目3-9 程序设计联考

### 题目3-10 念数字

### 题目3-11 单词长度

```cpp
#include <stdio.h>

int main()
{
    char ch;
    int length = 0;
    int first_word = 1;

    while (scanf("%c", &ch) && ch != '.')
    {
        if (ch == ' ')
        {
            if (length > 0)
            {
                if (!first_word)
                {
                    printf(" ");
                }
                printf("%d", length);
                length = 0;
                first_word = 0;
            }
        }
        else
        {
            length++;
        }
    }

    // 输出最后一个单词的长度
    if (length > 0)
    {
        if (!first_word)
        {
            printf(" ");
        }
        printf("%d", length);
    }

    return 0;
}
```

### 题目3-12 奇偶分家

```cpp
#include <stdio.h>

int main() 
{
    int N;
    int odd_count = 0, even_count = 0;

    // 输入 N
    scanf("%d", &N);

    // 输入 N 个整数并统计奇偶数
    for (int i = 0; i < N; i++) 
    {
        int num;
        scanf("%d", &num);

        // 判断是奇数还是偶数
        if (num % 2 == 0) 
        {
            even_count++;  // 偶数
        } else 
        {
            odd_count++;   // 奇数
        }
    }

    // 输出奇数和偶数的个数
    printf("%d %d\n", odd_count, even_count);

    return 0;
}
```

### 题目3-13 寻找250

```cpp
#include <stdio.h>

int main() 
{
    int num;
    int index = 1;  // 从第1个数字开始计数

    // 不知道输入有多少个数字，所以用无限循环
    while (scanf("%d", &num) != EOF) 
    {
        if (num == 250) 
        {
            printf("%d\n", index);
            return 0;  // 找到后结束程序
        }
        index++;  // 移动到下一个数字
    }

    return 0;
}
```

### 题目3-14 回文数

```cpp
#include <stdio.h>

int main() {
    int num;

    // 输入一个5位数
    scanf("%d", &num);

    // 提取每一位数字
    int digit1 = num / 10000;          // 万位
    int digit2 = (num / 1000) % 10;   // 千位
    int digit4 = (num / 10) % 10;     // 十位
    int digit5 = num % 10;            // 个位

    // 判断是否是回文数
    if (digit1 == digit5 && digit2 == digit4) 
    {
        printf("yes\n");
    } else 
    {
        printf("no\n");
    }

    return 0;
}
```

### 题目3-15 输出闰年

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

### 题目3-16 统计字符

```cpp
#include <stdio.h>

int main() {
    char c;
    int letter = 0, blank = 0, digit = 0, other = 0;

    for (int i = 0; i < 10; i++) 
    {
        c = getchar();

        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) 
        {
            letter++;
        } 
        else if (c == ' ' || c == '\n') 
        {
            blank++;
        } 
        else if (c >= '0' && c <= '9') 
        {
            digit++;
        } 
        else 
        {
            other++;
        }
    }
    printf("letter = %d, blank = %d, digit = %d, other = %d\n", letter, blank, digit, other);

    return 0;
}
```

### 题目3-17 查验身份证

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

### 题目3-18 谁先倒

```cpp
#include <stdio.h>

int main()
{
    int A[2][101], B[101][101];
    int a, b;
    scanf("%d %d", &a, &b);
    int n, counta = 0, countb = 0;
    scanf("%d", &n);
    int firsta = 0, firstb = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &A[0][i], &A[1][i], &B[0][i], &B[1][i]);
        if (A[0][i] + B[0][i] == A[1][i] && A[0][i] + B[0][i] == B[1][i])
            continue;

        else if (A[0][i] + B[0][i] == A[1][i] && !firsta && !firstb)
        {
            counta++;
            if (counta == a + 1)
            {
                firsta = 1;
            }
        }
        else if (A[0][i] + B[0][i] == B[1][i] && !firsta && !firstb)
        {
            countb++;
            if (countb == b + 1)
            {
                firstb = 1;
            }
        }
        else
            continue;
    }
    if (firsta && firstb)
        printf("A\n%d\nB\n%d", countb, counta);
    else if (firsta)
        printf("A\n%d", countb);
    else if (firstb)
        printf("B\n%d", counta);
}
```

### 题目3-19 输出GPLT

```cpp
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char input[10001]; // 输入字符串，最大长度为10000

    // 读取输入字符串
    scanf("%s", input);

    // 用于计数 G, P, L, T 的出现次数
    int count[4] = {0}; // count[0] -> 'g', count[1] -> 'p', count[2] -> 'l', count[3] -> 't'

    // 统计各字符的个数（不区分大小写）
    for (int i = 0; input[i] != '\0'; i++)
    {
        char ch = tolower(input[i]); // 转换为小写字符
        if (ch == 'g')
            count[0]++;
        else if (ch == 'p')
            count[1]++;
        else if (ch == 'l')
            count[2]++;
        else if (ch == 't')
            count[3]++;
    }

    // 按照 GPLT 的顺序输出字符，直到某个字符用完
    while (count[0] > 0 || count[1] > 0 || count[2] > 0 || count[3] > 0)
    {
        if (count[0] > 0)
        {
            printf("G");
            count[0]--;
        }
        if (count[1] > 0)
        {
            printf("P");
            count[1]--;
        }
        if (count[2] > 0)
        {
            printf("L");
            count[2]--;
        }
        if (count[3] > 0)
        {
            printf("T");
            count[3]--;
        }
    }

    return 0;
}
```

### 题目3-20 大笨钟

```cpp
#include <stdio.h>

int main() 
{
    int hh, mm;

    scanf("%d:%d", &hh, &mm);

    if (hh < 12 || (hh == 12 && mm == 0))
    {
        printf("Only %02d:%02d.  Too early to Dang.", hh, mm);
    }
    else 
    {
        int dongs = hh - 12;
        if (mm > 0) 
        {
            dongs++;
        }
        for (int i = 0; i < dongs; i++) 
        {
            printf("Dang");
        }
    }

    return 0;
}
```
