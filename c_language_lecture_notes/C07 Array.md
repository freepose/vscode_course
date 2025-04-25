# C07 数组

引导：

(a) 什么是数组？先简单的介绍数组，从现实角度来理解。再强调，为什么需要数组？

(b) 最后，数组怎么用？通过若干例子。

难点：涉及到内存，因此也有一点指针的内容。

```cpp
// 数组：引导
#include <stdio.h>

int main()
{
    // We have 36 students in our classroom.
    // How many variables do we need to denote scores of student?
    int math1 = 5;
    int math2 = 6;
    // We need many variable in a common time.

    // Dr. wang introdce array data type.
    int math_scores1[36];
    int math_scores2[36] = {0};
    int math_scores3[36] = {5, 6};

    // How to access an array?

    // The access array using indices. The indices are zero-based integers.
    scanf("%d", &math_scores1[0]);    // we write the first student's math score using index.
    printf("%d\n", math_scores3[1]);    // we read the first student's math score using index.

    return 0;
}
```

## (1) 介绍

分析：按照王老师的理解，把相同变量类型的数据在内存中连续存放。现实需求也是如此，如果多次声明同一种类型的变量，使得这些变量变得难以访问。

```cpp
 int math_scores[35]; // 声明35个变量，来表示35个同学的数学成绩
```

以上声明的这35个变量的初始值是随机的，因此需要做初始化。

```cpp
// 数组：初始化
#include<stdio.h>
#include<memory.h>

int main()
{
    int math_scores[35] = {0, 1};    // 第0个变量为0， 第1变量为1，同理可以往下做。

    for (int i = 0; i < 35; i++)    // 访问并初始化
    {
        math_scores[i] = i;// zero-based
    }

    memset(math_scores, 0, sizeof(int) * 35);   // 把数组的所有内容，全部置0

    return 0;
}
```

小结，什么是数组？同一种变量类型的有序集合，并在内存中连续存放。

```cpp
// 数组：存和取。这里用随机数来存，顺序输出
#include <stdio.h>

int main()
{
    int n = 10;
    short scores[100] = {55, 23, 8, 11, 22, 89, 0, -1, 78, 186};  

    // output to console
    for (int i = 0; i < n; i++)
    {
        printf("scores[%d] = %d\n", i, scores[i]);
    }

    // what is an array? varialbes of a common data type are consecutively accessed in MM.

    return 0;
}
```

## (2) 数组怎么用？

题目：输入10个整数，输出大于均值的数。

分析：假如，不存储这个10数字可以吗？不行，需要存储并计算均值。后遍历输出大于均值的数。

```cpp
// 数组：数组访问和遍历
#include<stdio.h>

int main()
{
    int num[10] = { 0 }; // 静态开辟数组：长度不大的数组可以
    float average = 0.;

    // read from console, and average them.
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &num[i]);
        average += num[i];
    }
    average /= 10;
    printf("average = %.2f\n", average);

    // write to console
    for (int i = 0; i < 10; i++)
    {
        if (num[i] > average)
        {
            printf("%d\t", num[i]);
        }
    }

    return 0;
}
```

题目：用数组计算Fibonacci数列的前10个数，并按每行打印5个数的格式输出。

分析：数组是可以存下数列的每个值，因此在往前计算a_{n}的时候，直接方位更早的两个变量a_{n-1}, a_{n-2}。

```cpp
// 数组：斐波那契数列
#include<stdio.h>

int main()
{
    int a[20] = {1, 1}, count = 0; 

    // calculate Fib 20 numbers
    for (int i = 2; i < 20; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }

    // write to console
    for (int i = 0; i < 20; i++)
    {
        printf("%d%c", a[i], (i + 1) % 5 == 0 ? '\n' : '\t');
    }

    return 0;
}
```

## (3) 若干例子

#### (a) 例7-3 顺序查找法

顺序查找法也叫Brute Force Search暴力搜索，复杂度为$O(n)$

分析：随机生成一个1到100数列，长度为10，输出大于50的数字

```cpp
// 例7-3 顺序查找法，也叫Brute Force Search暴力搜索
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a[10] = {0}; 
    const int a_len = 10;

    srand(10);  // fix random seed

    // 随机生成1到100的数字：10
    for (int i = 0; i < a_len; i++)
    {
        a[i] = rand() % 100 + 1;  
    }

    // write to console
    for (int i = 0; i < a_len; i++)
    {
        if (a[i] > 50)
        {
            printf("%d\t", a[i]);
        }
    }

    return 0;
}
```

### (b) 例7-4 查找最小值

分析：用循环标记法。

```cpp
// 例7-3 查找数组中最小值
// 数组：找最小值
#include <stdio.h>

int main()
{
    int n = 10, min_i = 0;
    short scores[100] = { 55, 23, 8, 11, 22, 89, 0, -1, 78, 186 };

    // recall previous case: given several number read from console, output the minimum value
    // mark while loop: mark object is value

    // for array, read values in an array, output index corresponding to the minimun value.
    // mark while loop: mark object is index

    // output to console
    for (int i = 0; i < n; i++)
    {
        printf("scores[%d] = %d\n", i, scores[i]);
    }

    printf("\n---------------------------------\n");

    // find minimum value and its index
    for (int i = 1; i < n; i++)
    {
        if (scores[min_i] > scores[i])
        {
            min_i = i;
        }
    }

    printf("minimum value find at scores[%d] = %d", min_i, scores[min_i]);

    return 0;
}
```

### (c) 选择排序

分析：什么是选择排序？在(3-b)，用标记的方法查找数组的最小值。多次使用这个方法，是否可以得到一个有序的数组。这就是循环标记控制法。

```cpp
// 选择排序
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int arr[10] = { 0 }, min_index, temp;
    int n = 10;

    srand(10);  // fix random seed

    // 随机生成10个1到100的数字
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10000 + 1;
    }

    // Sort the array using selection sort algorithm
    for (int i = 0; i < n - 1; i++)
    {
        min_index = i;  // 要标记的是：数组的下标，
                        // 以方便后续交换i和j的位置，保证i位置的值是最小的
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min_index] > arr[j])
            {
                min_index = j;
            }
        }

        // 交换两个数组
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }

    // 显示在控制台：没5个数字换行
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", arr[i], (i + 1) % 5 == 0 ? '\n' : '\t');
    }
    return 0;
}
```

改进选择排序：判断除i指定之外的最小值是否比a[i]大，再交换

```cpp
// 改进选择排序：通过多次找最小值得到值有序的序列。循环标记控制法。
#include <stdio.h>

int main()
{
    int n = 10, min_j = 0;
    short scores[100] = { 55, 23, 8, 11, 22, 89, 0, -1, 78, 186 }, temp;

    // output to console
    for (int i = 0; i < n; i++)
    {
        printf("scores[%d] = %d\n", i, scores[i]);
    }

    // find minimum value and its index
    for (int i = 0; i < n - 1; i++)
    {
        min_j = i + 1;
        for (int j = min_j + 1; j < n; j++)
        {
            if (scores[min_j] > scores[j])
            {
                min_j = j;
            }
        }

        // swap min value and i-index value
        if (scores[i] > scores[min_j])
        {
            temp = scores[i];
            scores[i] = scores[min_j];
            scores[min_j] = temp;
        }
    }

    printf("\n---------------------------------\n");

    // output to console
    for (int i = 0; i < n; i++)
    {
        printf("scores[%d] = %d\n", i, scores[i]);
    }
    return 0;
}
```

### (d) 折半查找

分析：类似猜数字的游戏，每次给出一个数字，可以知道对，高了，或低了。折半的策略类似如此。备注：当x小于数组中间的数，则high移动到mid - 1；当x大于数组中间的数，则low移动到mid+1；如果相等，则标记并停止搜索。

```cpp
// 二分查找
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a[10] = { 1, 2, 8, 9, 10};
    int n = 5;
    int x = 20, x_index = -1;
    int low = 0, high = n - 1;
    int mid = (low + high) / 2;

    // 显示在控制台：每5个数字换行
    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }

    // binary search
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == x)
        {
            x_index = mid;
            break;
        }
        else if (a[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (x_index != -1)
    {
        printf("%d index is find at %d\n", x, x_index);
    }
    else
    {
        printf("not found!");
    }

    return 0;
}
```

## (4) 二维数组

引导：相同变量放在一起，统一管理，因此有了数组。二维数组，就是数组的数组。通俗叫法，矩阵。

如果是数组也看成是一个变量？把两个数组放在一起，统一管理，因此有了二维数组。

如果二维数组也看成是一个变量？把两个二维数组放在一起，统一管理，因此有了三维数组。

如果, ...., 有了n维数组。

```cpp
// 二维数组：判断今天是今年的第几天
#include <stdio.h>

int main()
{
    int a2d[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},  // 非闰年
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}   // 闰年
    };
    int year, month, day, day_count = 0;

    scanf("%d-%d-%d", &year, &month, &day);

    year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? 1 : 0;
    for (int i = 1; i < month; i++)
    {
        day_count += a2d[year][i];
    }
    printf("The %d of this year!\n", day_count + day);

    return 0;
}
```

二维数组还可以用来杨辉三角形。请问，怎么做？

## (5) 字符数组

讲解：前面讲过一个数组都放整数，即整型数组；那么，一个数组都放**字符**，则被称作**字符数组**。

```cpp
// 字符串数组
#include <stdio.h>

int main()
{
    char buff[20] = {'H', 'e', 'l', 'l', 'o', 0, 'W', 'o'};    // 自动补0

    char* s = "Hello";    // 自动补0

    printf("%s\n", buff);
    printf("%s\n", s);

    printf("%d %d %d", strlen(buff), strlen(s), strcmp(buff, s));

    return 0;
}
```

## (6)pintia第7章：数组

### 题目7-1 房号的玄机

```cpp
#include <stdio.h>

int main()
{
    char num[9];
    int k;
    scanf("%s %d", num, &k);
    printf("level=");
    for (int i = 0; i < k; i++)
    {
        printf("%c", num[i]);
    }
    printf(",room=");
    for (int i = k; i < 8; i++)
    {
        printf("%c", num[i]);
    }
    return 0;
}
```

### 题目7-2 找出不是两个数组共有的元素

```cpp
#include <stdio.h>

int main()
{
    int N1, N2;
    int arr1[20], arr2[20];
    int unique[40];
    int unique_count = 0;

    // 读取第一个数组
    scanf("%d", &N1);
    for (int i = 0; i < N1; i++)
    {
        scanf("%d", &arr1[i]);
    }

    // 读取第二个数组
    scanf("%d", &N2);
    for (int i = 0; i < N2; i++)
    {
        scanf("%d", &arr2[i]);
    }

    // 找出第一个数组中不在第二个数组中的元素
    for (int i = 0; i < N1; i++)
    {
        int found = 0;
        for (int j = 0; j < N2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            int already_in_unique = 0;
            for (int k = 0; k < unique_count; k++)
            {
                if (unique[k] == arr1[i])
                {
                    already_in_unique = 1;
                    break;
                }
            }
            if (!already_in_unique)
            {
                unique[unique_count++] = arr1[i];
            }
        }
    }

    // 找出第二个数组中不在第一个数组中的元素
    for (int i = 0; i < N2; i++)
    {
        int found = 0;
        for (int j = 0; j < N1; j++)
        {
            if (arr2[i] == arr1[j])
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            int already_in_unique = 0;
            for (int k = 0; k < unique_count; k++)
            {
                if (unique[k] == arr2[i])
                {
                    already_in_unique = 1;
                    break;
                }
            }
            if (!already_in_unique)
            {
                unique[unique_count++] = arr2[i];
            }
        }
    }

    // 输出结果
    for (int i = 0; i < unique_count; i++)
    {
        if (i > 0)
        {
            printf(" ");
        }
        printf("%d", unique[i]);
    }
    printf("\n");

    return 0;
}
```

### 题目7-3 删除重复字符

本题要求编写程序，将给定字符串去掉重复的字符后，按照字符ASCII码顺序从小到大排序后输出。

输入格式：
输入是一个以回车结束的非空字符串（少于80个字符）。

输出格式：
输出去重排序后的结果字符串。

输入样例：
ad2f3adjfeainzzzv

输出样例：
23adefijnvz

**解题思路**

1. **去重**：使用一个数组 `count` 来记录每个字符是否已经出现过。遍历输入字符串时，如果某个字符已经出现过，则跳过；否则，将其标记为已出现。

2. **排序**：由于字符的 ASCII 码范围是固定的（0 到 127），可以直接按照 ASCII 码顺序遍历 `count` 数组，将出现过的字符按顺序输出。

3. **实现步骤**：
    - 初始化一个大小为 128 的数组 `count`，所有元素初始化为 0。
    - 遍历输入字符串，对于每个字符，将其对应的 `count` 数组位置标记为 1。
    - 遍历 `count` 数组，将值为 1 的字符按顺序输出。

4. **时间复杂度**：由于只需遍历字符串一次（O(n)）和固定大小的 `count` 数组一次（O(128)），总时间复杂度为 O(n)。


```cpp
#include <stdio.h>

int main()
{
    char str[80];
    int count[128] = {0};
    int i = 0;
    char c;

    while ((c = getchar()) != '\n')
    {
        str[i++] = c;
    }
    str[i] = '\0';

    for (i = 0; str[i] != '\0'; i++)
    {
        count[str[i]]++;
    }

    for (i = 0; i < 128; i++)
    {
        if (count[i] > 0)
        {
            printf("%c", i);
        }
    }

    return 0;
}
```

### 题目7-4 简化的插入排序

```cpp
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[10];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int x;
    scanf("%d", &x);

    int b[11];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (x < a[i])
        {
            break;
        }
        b[i] = a[i];
    }
    b[i] = x;
    for (int j = i; j < n; j++)
    {
        b[j + 1] = a[j];
    }

    for (int i = 0; i < n + 1; i++)
    {
        printf("%d ", b[i]);

    }
    return 0;
}
```

### 题目7-5 数组循环左移

```cpp
#include <stdio.h>

void reverse(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[100];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    m = m % n; // 如果m大于n，取m对n的模

    // 反转前m个元素
    reverse(arr, 0, m - 1);
    // 反转后n-m个元素
    reverse(arr, m, n - 1);
    // 反转整个数组
    reverse(arr, 0, n - 1);

    // 输出结果
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

### 题目7-6 方阵循环右移

```cpp
#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[6][6];
    int result[6][6];

    // 读取方阵
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    // 计算循环右移后的方阵
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][(j + m) % n] = matrix[i][j];
        }
    }

    // 输出结果
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```

### 题目7-7 选择法排序

```cpp
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[10];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // 使用选择排序法进行排序
    for (int i = 0; i < n - 1; i++)
    {
        int max_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[max_idx])
            {
                max_idx = j;
            }
        }
        // 交换最大值到当前位置
        int temp = arr[i];
        arr[i] = arr[max_idx];
        arr[max_idx] = temp;
    }

    // 输出结果
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

### 题目7-8 冒泡法排序

```cpp
#include <stdio.h>

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    int arr[100];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    // 使用冒泡排序法进行排序，扫描K遍
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < N - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // 输出结果
    for (int i = 0; i < N; i++)
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

### 题目7-9 数列求和-加强版

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

### 题目7-10 统计大写辅音字母

```cpp
#include <stdio.h>
#include <ctype.h>

int main() 
{
    char str[81];
    int count = 0;

    // Read the input string
    fgets(str, 81, stdin);

    // Loop through each character in the string
    for (int i = 0; str[i] != '\0'; i++) 
    {
        // Check if the character is an uppercase consonant
        if (isupper(str[i]) && str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U') 
        {
            count++;
        }
    }

    // Print the count of uppercase consonants
    printf("%d\n", count);

    return 0;
}
```

### 题目7-11 统计字符出现次数

```cpp
#include <stdio.h>
#include <string.h>

int main()
{
    char str[81];
    char ch;
    int count = 0;

    // 读取输入字符串
    fgets(str, 81, stdin);

    // 读取输入字符
    ch = getchar();

    // 遍历字符串中的每个字符
    for (int i = 0; i < strlen(str); i++)
    {
        // 检查当前字符是否与输入字符匹配
        if (str[i] == ch)
        {
            count++;
        }
    }

    // 输出字符出现的次数
    printf("%d\n", count);

    return 0;
}
```

### 题目7-12 交换最小值和最大值

```cpp
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[10];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // 找到最小值及其索引
    int minIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[minIndex])
        {
            minIndex = i;
        }
    }

    // 交换最小值和第一个数
    int temp = a[0];
    a[0] = a[minIndex];
    a[minIndex] = temp;

    // 找到最大值及其索引
    int maxIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[maxIndex])
        {
            maxIndex = i;
        }
    }

    // 交换最大值和最后一个数
    temp = a[n - 1];
    a[n - 1] = a[maxIndex];
    a[maxIndex] = temp;

    // 输出交换后的数组
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
```

### 题目7-13 打印杨辉三角

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

### 题目7-14 螺旋方阵

```cpp
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int matrix[10][10] = {0};
    int num = 1;
    int left = 0, right = n - 1, top = 0, bottom = n - 1;

    while (num <= n * n)
    {
        // 从左到右填充上边
        for (int i = left; i <= right; i++)
        {
            matrix[top][i] = num++;
        }
        top++;

        // 从上到下填充右边
        for (int i = top; i <= bottom; i++)
        {
            matrix[i][right] = num++;
        }
        right--;

        // 从右到左填充下边
        for (int i = right; i >= left; i--)
        {
            matrix[bottom][i] = num++;
        }
        bottom--;

        // 从下到上填充左边
        for (int i = bottom; i >= top; i--)
        {
            matrix[i][left] = num++;
        }
        left++;
    }

    // 输出螺旋方阵
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3d", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```

### 题目7-15 找鞍点

```cpp
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int matrix[6][6];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int saddlePointFound = 0;
    for (int i = 0; i < n; i++)
    {
        // 找到该行的最大值及其列索引
        int maxInRow = matrix[i][0];
        int colIndex = 0;
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] > maxInRow)
            {
                maxInRow = matrix[i][j];
                colIndex = j;
            }
        }

        // 检查该列索引处的值是否是该列的最小值
        int minInCol = matrix[i][colIndex];
        int isSaddlePoint = 1;
        for (int k = 0; k < n; k++)
        {
            if (matrix[k][colIndex] < minInCol)
            {
                isSaddlePoint = 0;
                break;
            }
        }

        if (isSaddlePoint)
        {
            printf("%d %d\n", i, colIndex);
            saddlePointFound = 1;
            break;
        }
    }

    if (!saddlePointFound)
    {
        printf("NONE\n");
    }

    return 0;
}
```

### 题目7-16 猴子选大王

```cpp
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int position = 0; // 初始位置为0
    for (int i = 2; i <= n; i++)
    {
        position = (position + 3) % i;
    }

    printf("%d\n", position + 1); // +1 是因为编号从1开始

    return 0;
}
```

### 题目7-17 出租

```cpp
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Element;

int compare(const void *a, const void *b) {
    return ((Element *)b)->value - ((Element *)a)->value;
}

int main() {
    char phone[12];
    scanf("%s", phone);

    Element elements[11];
    for (int i = 0; i < 11; i++) {
        elements[i].value = phone[i] - '0';
        elements[i].index = i;
    }

    qsort(elements, 11, sizeof(Element), compare);

    printf("int[] arr = new int[]{");
    for (int i = 0; i < 11; i++) {
        if (i > 0) {
            printf(",");
        }
        printf("%d", elements[i].value);
    }
    printf("};\n");

    printf("int[] index = new int[]{");
    for (int i = 0; i < 11; i++) {
        if (i > 0) {
            printf(",");
        }
        printf("%d", elements[i].index);
    }
    printf("};\n");

    return 0;
}
```

### 题目7-18 数字加密

```cpp
#include <stdio.h>

int main() 
{
    int number;
    scanf("%d", &number); // 读取输入的四位数

    // 提取每一位上的数字
    int digit1 = number / 1000; // 千位
    int digit2 = (number / 100) % 10; // 百位
    int digit3 = (number / 10) % 10; // 十位
    int digit4 = number % 10; // 个位

    // 每一位上的数字加9，然后除以10取余
    digit1 = (digit1 + 9) % 10;
    digit2 = (digit2 + 9) % 10;
    digit3 = (digit3 + 9) % 10;
    digit4 = (digit4 + 9) % 10;

    // 交换千位和十位，百位和个位
    int encryptedNumber = digit3 * 1000 + digit4 * 100 + digit1 * 10 + digit2;

    // 输出加密后的数，确保保留前导零
    printf("The encrypted number is %04d\n", encryptedNumber);

    return 0;
}
```

### 题目7-19 点赞

```cpp
#include <stdio.h>

int main() 
{
    int N;
    scanf("%d", &N);

    int count[1001] = {0}; // 用于统计特性标签的出现次数

    for (int i = 0; i < N; i++) 
    {
        int K;
        scanf("%d", &K);
        for (int j = 0; j < K; j++) 
        {
            int tag;
            scanf("%d", &tag);
            count[tag]++;
        }
    }

    int maxCount = 0;
    int maxTag = 0;
    for (int i = 1; i <= 1000; i++) 
    {
        if (count[i] > maxCount || (count[i] == maxCount && i > maxTag)) {
            maxCount = count[i];
            maxTag = i;
        }
    }

    printf("%d %d\n", maxTag, maxCount);

    return 0;
}
```
