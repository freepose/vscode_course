
# C06 数组

本章主要包括：一维数组、二维数组，和字符数组。

---

## 1. 一维数组的定义

数组，具有相同数据类型的元素的集合。

```c
int arr[5]; // 定义一个包含5个整数的数组
```

--- 

## 2. 一维数组的初始化

数组的初始化可以在定义时进行，也可以在定义后进行。

```c
int arr[5] = {1, 2, 3, 4, 5}; // 在定义时初始化

int arr[5]; // 先定义

arr[0] = 1; // 再逐个初始化
arr[1] = 2;
arr[2] = 3;
arr[3] = 4;
arr[4] = 5;

memset(arr, 0, sizeof(arr));    // 内存初始化为0

```

## 3. 一维数组的访问

下标访问：

```c
int arr[5] = {1, 2, 3, 4, 5};

for (int i = 0; i < 5; i++) 
{
    scanf("%d", &arr[i]);   // read console to variable
}

for (int i = 0; i < 5; i++) 
{
    printf("%d ", arr[i]); // get value from variable
}   
``` 

也可以由指针访问：

```c
int arr[5] = {1, 2, 3, 4, 5};

int *p = arr; // 指针指向数组首元素

for (int i = 0; i < 5; i++) 
{
    scanf("%d", p + i);   // read console to variable
}

for (int i = 0; i < 5; i++) 
{
    printf("%d ", *(p + i)); // get value from variable
}   
```
## 4. 一维数组找最大值（或最小值）

``` c
#include <stdio.h>

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int scores[10] = {67, 88, 76, 90, 56, 95, 72, 83, 80, 92};


    print_array(scores, 10);

    return 0;
}

```

## 5. 数组排序：选择排序

``` c
#include <stdio.h>

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int find_max(int arr[], int size)
{
    int index = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[index] < arr[i])
        {
            index = i;
        }
    }
    return index;
}

void selection_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int index = i; 
        for (int j = i + 1; j < size; j++)
        {
            if (arr[index] > arr[j])
            {
                index = j;
            }
        }

        if (index != i)
        {
            int temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
        }
    }
}

int main()
{
    int scores[10] = {67, 88, 76, 90, 56, 95, 72, 83, 80, 92};
    int i;

    print_array(scores, 10);
    selection_sort(scores, 10);
    print_array(scores, 10);

    return 0;
}
```

小结，其核心思想是，在一次排序过程找到最大值并交换。

## 5. 数组排序：冒泡排序

其核心，相邻两数两两比较。

``` c
void bubble_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        // 先尝试相邻两两比较
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
```

## 6. 二维数组的定义

二维数组可以看作是数组的数组，即每个元素都是一个一维数组。

```c
int arr[3][4]; // 定义一个包含3行4列的二维数组
```
## 7. 二维数组的初始化

二维数组的初始化可以在定义时进行，也可以在定义后进行。

```c
int arr[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
}; // 在定义时初始化

arr[0][0] = 1; // 再逐个初始化
arr[0][1] = 2;

// 也可以使用循环进行初始化
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 4; j++)
    {
        arr[i][j] = i * 4 + j + 1;
    }
}

memset(arr, 0, sizeof(arr));    // 用memset初始化为0
```

## 8. 字符数组的定义

字符数组是用于存储字符的数组，通常用于处理字符串。

```c
char buff[20]; // 定义一个包含20个字符的字符数组
```

字符数组的输入：

```c
#include <stdio.h>

int main()
{
    char buff[20];

    printf("请输入一个字符串：");
    scanf("%s", buff); // 输入字符串

    // gets(buff)

    printf("你输入的字符串是：%s\n", buff); // 输出字符串

    return 0;
}
```

有很多api，可以自己去查阅，常用的有：`strlen`、`strcpy`、`strcat`、`strcmp`等.



