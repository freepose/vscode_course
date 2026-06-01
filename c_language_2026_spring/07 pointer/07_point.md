
# C07 指针

## 1. 指针的定义

指针就是地址。

指针变量，指针类型的变量，用来存储地址。具体来说，整型类型的指针变量，用来存储整型变量的地址；字符型类型的指针变量，用来存储字符型变量的地址；等等。举个例子：
```c
int a = 10; // 定义一个整型变量a，值为10
int *p; // 定义一个指针变量p，类型为int*
p = &a; // 将变量a的地址赋值给指针变量p
```

结构体指针变量，比如Student *s;，用来存储Student类型变量的地址。
``` c
struct Student {
    char name[20];
    int age;
};
struct Student s1 = {"Alice", 20}; // 定义一个Student类型的变量s1
struct Student *s; // 定义一个Student类型的指针变量s
s = &s1; // 将变量s1的地址赋值给指针变量s
```

小结，既然指针是地址，那么所有指针的大小都是一样的，都是4字节（32位系统）或者8字节（64位系统）。指针变量的类型决定了它指向的变量的类型，但不影响指针变量本身的大小。


## 2. 指针的使用

指针变量存储了一个地址，我们可以通过这个地址来访问对应的变量。继续上面的例子：
```c
printf("a = %d\n", a); // 输出a的值
printf("p = %p\n", p); // 输出p存储的地址
printf("*p = %d\n", *p); // 输出p指向的变量的值，即a的值
```

### 3. 当指针遇到数组

数组名就是一个指针常量，指向数组的第一个元素。比如：
```c
int arr[5] = {1, 2, 3, 4, 5}; // 定义一个整型数组
printf("arr = %p\n", arr); // 输出数组名的地址
printf("arr[0] = %d\n", arr[0]); // 输出数组的
printf("*arr = %d\n", *arr); // 输出数组的第一个元素
```

用指针（或指针变量）来访问数组元素：
```c

#include <stdio.h>

int main()
{
    int arr[5] = {1, 2, 3, 4, 5}; // 定义一个整型数组

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(arr + i)); // 使用指针访问数组元素
    }

    // OR

    for (int *p = arr; p < arr + 5; p++)
    {
        printf("%d ", *p); // 使用指针访问数组元素
    }

    return 0;
}

```

现在需要若干个字符串，使用到指针字符串数组：
```c
#include <stdio.h>

int main()
{
    char *strs[] = {"Hello", "World", "C", "Programming"}; // 定义一个指针字符串数组

    for (int i = 0; i < 4; i++)
    {
        printf("%s ", strs[i]); // 输出指针字符串数组的元素
    }

    return 0;
}
```

## 4. 当指针遇到函数


当数组需要传递给函数时，传递的其实是数组的地址，即指针。比如：
```c

#include <stdio.h>

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]); // 使用指针访问数组元素
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5}; // 定义一个整型数组
    printArray(arr, 5); // 将数组名作为实参传递给函数

    return 0;
}

```

二维数组传递给函数时，传递的也是数组的地址，即指针。比如：
```c

#include <stdio.h>

void printMatrix(int (*matrix)[3], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", matrix[i][j]); // 使用指针访问二维数组元素
        }
        printf("\n");
    }
}

int main()
{
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}}; // 定义一个二维数组
    printMatrix(matrix, 2); // 将二维数组名作为实参传递给函数

    return 0;
}

```


函数名也是一个指针常量，指向函数的入口地址。比如，
```c

#include <stdio.h>

void foo()
{
    printf("Hello, World!\n");
}

int main()
{
    printf("foo = %p\n", foo); // 输出函数名的地址
    foo(); // 调用函数

    return 0;
}

```

当然，我们也可以通过函数指针来调用函数：
```c

// 函数指针

#include <stdio.h>

void foo()
{
    printf("Hello, World!\n");
}

int main()
{
    void (*fp)() = foo; // 定义一个函数指针变量fp，指向函数foo
    printf("fp = %p\n", fp); // 输出函数指针变量fp的值，即函数foo的地址
    fp(); // 通过函数指针调用函数foo

    return 0;
}

```
