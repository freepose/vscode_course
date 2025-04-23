# C09 结构体

引导：之前讲过相同的变量连续的放在一起，叫做数组。那么，不同的变量连续的放在一起，就需要用到结构体。struct关键字。

## (1) 如何定义一个学生？

```cpp
// 结构体：如何描述一个学生
#include <stdio.h>
#include <memory.h>

struct student
{
    char number[10];    // 学号
    char name[10];      // 姓名
    int math, english, history; //成绩
    float average;
};

int main()
{
    struct student s1 = {"0001", "Wang", 20, 20, 20, 0};

    // print a student's information
    printf("%s\t%s\t%d\t%d\t%d\t%.2f", s1.number, s1.name, s1.math, s1.english, s1.history, s1.average);

    // memset(&s1, 0, sizeof(s1)); // 直接通过内存的初始化

    return 0;
}
```

## (2) 当结构体遇到函数

需求：把一个结构体传到一个函数去。利用指针传递。

```cpp
// 结构体：传递结构体到函数
#include <stdio.h>
#include <memory.h>

typedef struct // 类型重定义
{
    char number[10];    // 学号
    char name[10];      // 姓名
    int math, english, history; //成绩
    float average;
} Student;

void print_a_student(Student *ps)
{
    // 结构体指针变量，取内容用 ->，当然也可以*ps之后再选择
    printf("%s\t%s\t%d\t%d\t%d\t%.2f\n", 
        (*ps).number, ps->name, ps->math, ps->english, ps->history, ps->average);
}

int main()
{
    Student s1 = { "0001", "Wang", 20, 20, 20, 0 };
    Student s2 = { "0002", "Zhang", 20, 30, 20, 0 };

    // print a student's information

    // memset(&s1, 0, sizeof(s1)); // 直接通过内存的初始化
    print_a_student(&s1);
    print_a_student(&s2);

    return 0;
}
```

## (3) 当结构体数组遇到函数

用学生信息管理系统作为例子

```cpp
/*****
 * 
 * Student information system
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct type named StudentType

struct _student_type
{
    char student_id[12]; 
    char name[20];      
    char class_id[20];   
    char gender[4];     
    char phone[12];      
    char address[200];   
    char interest[200];  
};

typedef struct _student_type StudentType;


// Deliever a student's information using struct pointer
void print_a_student(StudentType *p)
{
    // print a student's information in a line, and use '\t' to separate each field, '\n' at the end
    // Here, we have two points: deliver using struct pointer, and use '->' to access struct fields
    printf("%s\t", p->student_id);    // p->student_id or (*p).student_id
    printf("%s\t", p->name);
    printf("%s\t", p->class_id);
    printf("%s\t", p->gender);
    printf("%s\t", p->phone);
    printf("%s\t", p->address);
    printf("%s\n", p->interest);
}

// Deliver student array using struct pointer
void print_students(StudentType *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        print_a_student(p + i);
    }
}

// Read student information from file: data/微电2411学生信息.csv
void read_students(char *csv_filename, StudentType *p, int *n)
{
    // Open file
    FILE *fp = fopen(csv_filename, "r");
    if (fp == NULL)
    {
        printf("Failed to open file %s\n", csv_filename);
        return;
    }

    *n = 0;
    // Read file
    char line[1024];
    // skip first line
    fgets(line, 1024, fp);

    while (fgets(line, 1024, fp) != NULL)
    {
        // Parse line
        char *student_id = strtok(line, ",");
        char *name = strtok(NULL, ",");
        char *class_id = strtok(NULL, ",");
        char *gender = strtok(NULL, ",");
        char *phone = strtok(NULL, ",");
        char *address = strtok(NULL, ",");
        char *interest = strtok(NULL, "\n");

        // from buffer to struct
        strcpy(p[*n].student_id, student_id);
        strcpy(p[*n].name, name);
        strcpy(p[*n].gender, gender);
        strcpy(p[*n].phone, phone);
        strcpy(p[*n].address, address);
        strcpy(p[*n].interest, interest);

        (*n)++;
    }
}

void sort_by_student_id(StudentType *p, int n)
{
    // Select sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(p[i].interest, p[j].interest) > 0)
            {
                // Swap between two structs
                StudentType temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}


int main()
{
    StudentType weidian[35] = { {"2024010100", "张三", "2411", "男", "13812345678", "北京市海淀区中关村大街1号", "篮球,足球,乒乓球"},
                                {"2024010101", "李四", "2411", "男", "13812345679", "北京市海淀区中关村大街2号", "游泳,健身,跑步"},
                                {"2024010102", "王五", "2411", "男", "13812345680", "北京市海淀区中关村大街3号", "唱歌,跳舞,画画"} };

    int n = 3;

    char csv_file[] = "data/微电2411学生信息.csv";

    // memset(weidian, 0, sizeof(weidian));

    read_students(csv_file, weidian, &n);
    printf("Total students: %d\n", n);

    sort_by_student_id(weidian, n);
    print_students(weidian, n);

    return 0;
}
```

学生信息管理系统：电子2411的内容

```cpp
/*****
 *
 *  Student information system
 *
 */

#include <stdio.h>
#include <string.h>

struct student
{
    char number[20];   // 学号
    char name[20];     // 姓名：一个汉字占两个字节
    char class[20];    // 班级
    char gender[4];    // 性别
    char phone[20];    // 手机号
    char address[100]; // 家庭地址
    char interest[20]; // 兴趣
};

typedef struct student Student;

void read_students(char *csv_filename, Student *pss, int *p_num_students)
{
    // :param csv_filename: the csv file name
    // :param pss: the pointer of the student array
    // :param p_num_students: the pointer of the number of students, _num_students varies as the csv file
    FILE *fp = fopen(csv_filename, "r");
    if (fp == NULL)
    {
        printf("Error: cannot open file %s\n", csv_filename);
        return;
    }

    char line[1024];
    // skip the first line
    fgets(line, 1024, fp);

    int i = 0;
    while (fgets(line, 1024, fp))
    {
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s",
               pss[i].number, pss[i].name, pss[i].class, pss[i].gender, pss[i].phone, pss[i].address, pss[i].interest);
        i++;
    }
    *p_num_students = i; // update the number of students
}

void print_a_student(Student *ps)
{
    // print a student information, use tab to separate the fields, and use a new line to separate the students
    printf("%s\t", ps->number);
    printf("%s\t", ps->name);
    printf("%s\t", ps->class);
    printf("%s\t", ps->gender);
    printf("%s\t", ps->phone);
    printf("%s\t", ps->address);
    printf("%s\n", ps->interest);
}

void print_students(Student *pss, int n)
{
    // print all students information
    for (int i = 0; i < n; i++)
    {
        print_a_student(pss + i);
    }
}

void sort_students(Student *pss, int n)
{
    // sort the students by a struct member variable, the sort algorithm is bubble sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(pss[j].address, pss[j + 1].address) > 0)
            {
                Student temp = pss[j];
                pss[j] = pss[j + 1];
                pss[j + 1] = temp;
            }
        }
    }
}

void search_stduent_address(Student *pss, int n, char *target)
{
    // Print student address contains target strings
    for (int i = 0; i < n; i++)
    {
        if (strstr(pss[i].address, target))
        {
            print_a_student(pss + i);
        }
    }
}

int main()
{
    Student ss[100];
    int num_students = 1;
    char csv_filename[] = "data/微电2411电子2411学生信息.csv";

    read_students(csv_filename, ss, &num_students);
    // print_students(ss, num_students);

    sort_students(ss, num_students);
    // printf("\nAfter sorting:\n");
    // print_students(ss, num_students);

    search_stduent_address(ss, num_students, "贵州");

    return 0;
}
```

## (4) pintia第9章：结构体

### 题目9-1 一帮一

```cpp
#include <stdio.h>
#include <string.h>

typedef struct _student {
    int gender;
    char name[9];
} Student;

int main() {
    Student students[50];
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %s", &students[i].gender, students[i].name);
    }

    int mid = n / 2;
    int used[50] = {0}; // 用于标记学生是否已经分组

    // 从前面找下去，遇到男生则从后面找女生，遇到女生则从后面找男生
    for (int i = 0; i < mid; i++) {
        if (used[i]) continue; // 跳过已经分组的学生

        if (students[i].gender == 1) { // 遇到男生
            for (int j = n - 1; j >= mid; j--) {
                if (students[j].gender == 0 && !used[j]) { // 找到未分组的女生
                    printf("%s %s\n", students[i].name, students[j].name);
                    used[i] = 1;
                    used[j] = 1;
                    break;
                }
            }
        } else { // 遇到女生
            for (int j = n - 1; j >= mid; j--) {
                if (students[j].gender == 1 && !used[j]) { // 找到未分组的男生
                    printf("%s %s\n", students[i].name, students[j].name);
                    used[i] = 1;
                    used[j] = 1;
                    break;
                }
            }
        }
    }

    return 0;
}
```

### 题目9-2 时间换算

```cpp
#include <stdio.h>

int main() 
{
    int hh, mm, ss, n;
    scanf("%d:%d:%d", &hh, &mm, &ss);
    scanf("%d", &n);

    // 将起始时间转换为总秒数
    int total_seconds = hh * 3600 + mm * 60 + ss;
    // 加上给定的秒数
    total_seconds += n;
    // 计算新的时间
    hh = (total_seconds / 3600) % 24;
    mm = (total_seconds % 3600) / 60;
    ss = total_seconds % 60;

    // 输出结果时间
    printf("%02d:%02d:%02d\n", hh, mm, ss);

    return 0;
}
```

### 题目9-3 平面向量加法

```cpp
#include <stdio.h>
#include <math.h>

int main()
{
    double x1, y1, x2, y2;
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);

    double x = x1 + x2;
    double y = y1 + y2;

    // 处理-0.0的情况
    if (fabs(x) < 0.05) 
    {
        x = 0.0;
    }
    if (fabs(y) < 0.05) 
    {
        y = 0.0;
    }

    printf("(%.1f, %.1f)\n", x, y);

    return 0;
}
```

### 题目9-4 计算职工工资

```cpp
#include <stdio.h>

typedef struct {
    char name[10];
    float base_salary;
    float bonus_salary;
    float expense;
} Employee;

int main() {
    int n;
    scanf("%d", &n);

    Employee *employees = (Employee *)malloc(n * sizeof(Employee));


    for (int i = 0; i < n; i++) 
    {
        scanf("%s %f %f %f", employees[i].name, &employees[i].base_salary, &employees[i].bonus_salary, &employees[i].expense);
    }

    for (int i = 0; i < n; i++) 
    {
        float net_salary = employees[i].base_salary + employees[i].bonus_salary - employees[i].expense;
        printf("%s %.2f\n", employees[i].name, net_salary);
    }

    return 0;
}
```

### 题目9-5 查找书籍

```cpp
#include <stdio.h>

struct book
{
    char name[32];
    double price;
}s[10], high, low;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("\n");
        gets(s[i].name);
        scanf("%lf",&s[i].price);
    }

    high = low = s[0];
    for (int i = 1; i < n; i++)
    {
        if (s[i].price > high.price)
        {
            high = s[i];
        }

        if (s[i].price < low.price)
        {
            low = s[i];
        }
    }
    printf("%.2lf, %s\n", high.price, high.name);
    printf("%.2lf, %s\n", low.price, low.name);

    return 0;
}
```

### 题目9-6 通讯录的录入与显示

```cpp
#include<stdio.h>
struct people{
    char name[11];
    char birthday[11];
    char gender;
    char fixed[17];
    char mobile[17];
};
int main(void){
    int i,n,k,num;
    struct people s[10];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s %s %c %s %s",s[i].name,s[i].birthday,&s[i].gender,s[i].fixed,s[i].mobile);
    }
    scanf("%d",&k);
    for(i=0;i<k;i++){
        scanf("%d",&num);
        if(num>=0&&num<n)
            printf("%s %s %s %c %s\n",s[num].name,s[num].fixed,s[num].mobile,s[num].gender,s[num].birthday);
        else printf("Not Found\n");
    }

    return 0;
}
```

### 题目9-7 通讯录排序

```cpp
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[11];
    char birthday[9];
    char phone[18];
} Friend;

int compare(const void *a, const void *b) 
{
    Friend *friendA = (Friend *)a;
    Friend *friendB = (Friend *)b;
    return strcmp(friendA->birthday, friendB->birthday);
}

int main() {
    int n;
    scanf("%d", &n);
    Friend friends[10];

    for (int i = 0; i < n; i++) 
    {
        scanf("%s %s %s", friends[i].name, friends[i].birthday, friends[i].phone);
    }

    qsort(friends, n, sizeof(Friend), compare);

    for (int i = 0; i < n; i++) 
    {
        printf("%s %s %s\n", friends[i].name, friends[i].birthday, friends[i].phone);
    }

    return 0;
}
```

### 题目9-8 复数四则运算

```cpp
#include<stdio.h>
void shizi(double x,double y);    
void result(double x,double y);    
struct Love{        
    double shi,xu;
}love1,love2;
int main()
{    
    scanf("%lf%lf%lf%lf",&love1.shi,&love1.xu,&love2.shi,&love2.xu);
    double jia_shi = love1.shi + love2.shi;
    double jia_xu  = love1.xu  + love2.xu;
    double jian_shi = love1.shi - love2.shi;
    double jian_xu  = love1.xu  - love2.xu;
    double cheng_shi = love1.shi*love2.shi-love1.xu*love2.xu;
    double cheng_xu  = love1.xu*love2.shi+love1.shi*love2.xu;
    double chu_shi = (love1.shi*love2.shi+love1.xu*love2.xu)/(love2.shi*love2.shi+love2.xu*love2.xu);
    double chu_xu  = (love1.xu*love2.shi-love1.shi*love2.xu)/(love2.shi*love2.shi+love2.xu*love2.xu);
    shizi(love1.shi,love1.xu);
    printf(" + ");
    shizi(love2.shi,love2.xu);
    printf(" = ");
    result(jia_shi,jia_xu);    

    //减法
    shizi(love1.shi,love1.xu);
    printf(" - ");
    shizi(love2.shi,love2.xu);
    printf(" = ");
    result(jian_shi,jian_xu);
    shizi(love1.shi,love1.xu);
    printf(" * ");
    shizi(love2.shi,love2.xu);
    printf(" = ");
    result(cheng_shi,cheng_xu);
    shizi(love1.shi,love1.xu);
    printf(" / ");
    shizi(love2.shi,love2.xu);
    printf(" = ");
    result(chu_shi,chu_xu);    
    return 0;
}
void shizi(double x,double y)
{
    if(y<0)
        printf("(%.1lf%.1lfi)",x,y);
    else
        printf("(%.1lf+%.1lfi)",x,y);
}
void result(double rshi,double rxu)
{
    if(rxu<=0.05&&rxu>=-0.05)
        printf("%.1lf\n",rshi);
    else if(rshi<=0.05&&rshi>=-0.05)
        printf("%.1lfi\n",rxu);
    else if(rxu<0)
        printf("%.1lf%.1lfi\n",rshi,rxu);
    else
        printf("%.1lf+%.1lfi\n",rshi,rxu);
}
```

### 题目9-9 有理数加法

```cpp
#include <stdio.h>

// 计算最大公约数
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 计算最简分数
void simplify(int *numerator, int *denominator) {
    int divisor = gcd(*numerator, *denominator);
    *numerator /= divisor;
    *denominator /= divisor;
}

int main() {
    int a1, b1, a2, b2;
    scanf("%d/%d %d/%d", &a1, &b1, &a2, &b2);

    // 计算分子和分母
    int numerator = a1 * b2 + a2 * b1;
    int denominator = b1 * b2;

    // 化简分数
    simplify(&numerator, &denominator);

    // 输出结果
    if (denominator == 1) {
        printf("%d\n", numerator);
    } else {
        printf("%d/%d\n", numerator, denominator);
    }

    return 0;
}
```

### 题目9-10 有理数比较

```cpp
#include <stdio.h>

int main() {
    int a1, b1, a2, b2;
    char frac1[20], frac2[20];

    // 读取输入的两个分数
    scanf("%s %s", frac1, frac2);

    // 分别解析分子和分母
    sscanf(frac1, "%d/%d", &a1, &b1);
    sscanf(frac2, "%d/%d", &a2, &b2);

    // 比较大小
    long long cross1 = (long long)a1 * b2; // 计算 a1/b1 的交叉乘积
    long long cross2 = (long long)a2 * b1; // 计算 a2/b2 的交叉乘积

    // 输出结果
    if (cross1 > cross2) {
        printf("%s > %s\n", frac1, frac2);
    } else if (cross1 < cross2) {
        printf("%s < %s\n", frac1, frac2);
    } else {
        printf("%s = %s\n", frac1, frac2);
    }

    return 0;
}
```

## (5) pintia第10章：函数和程序结构

### 题目10-1 求组合数

```cpp
#include <stdio.h>

int main()
{
    // 利用组合数公式的对称性 (C(n, m) = C(n, n-m)) 来减少计算量。
    // 以下是一个不使用用户定义函数的C程序，用于计算组合数 (C(n, m)) 并输出结果：
    int m, n;
    scanf("%d %d", &m, &n);

    // 确保 m <= n - m 以减少计算量
    if (m > n - m)
    {
        m = n - m;
    }

    double result = 1.0;
    for (int i = 0; i < m; i++)
    {
        result *= (n - i);
        result /= (i + 1);
    }

    printf("result = %.0lf\n", result);

    return 0;
}
```

### 题目10-2 求幂之和

```cpp
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    long long sum = 0;
    long long power = 1; // 2^0 = 1

    for (int i = 1; i <= n; i++) 
    {
        power *= 2; // 计算2的i次幂
        sum += power;
    }

    printf("result = %lld\n", sum);

    return 0;
}
```

### 题目10-3 整数分解为若干项之和

```cpp
#include<stdio.h>
int sum=0;
int a[30];
void fenjieyinzi(int x,int n,int flag,int xiaxian){
    for(int i=xiaxian;i<=x;i++){
        if(x-i>0){
            a[flag]=i;
            fenjieyinzi(x-i,n,flag+1,i);
        }else if(x-i==0){
            a[flag]=i;
            for(int i=0;a[i]!=0;i++){
                if(i==0){
                    printf("%d=%d",n,a[i]);
                }else{
                    printf("+%d",a[i]);
                }
            }
            sum++;
            a[flag]=0;
            if(sum==4){
                printf("\n");
                sum=0;
            }else{
                if(flag!=0)
                printf(";");
            }
        }
    }
}
int main(){
    int flag=0;
    int sum=0;
    int n;
    scanf("%d",&n);
    fenjieyinzi(n,n,flag,1);
    return 0;
}
```

### 题目10-4 Have Fun with Numbers

```cpp
#include <stdio.h>
#define n 21 
int main(int argc, char *argv[])
{
    char a[n],ch;
    int i,len_a,b[n]={0},j,temp,flag=1;
    ch=getchar();
    for(i=0;ch!='\n';i++){
        a[i]=ch;
        ch=getchar();
    }
    len_a=i;
    for(i=0;i<len_a;i++){ 
        b[i]+=(a[i]-'0')*2/10;
        b[i+1]+=(a[i]-'0')*2%10;
    }

    if(b[0]!=0){
        printf("No\n");
        for(i=0;i<len_a+1;i++)
            printf("%d",b[i]);
        return 0;
    }
    int *p=&b[1],c[len_a];
    for(i=0;i<len_a;i++)
        c[i]=p[i];
    for(i=0;i<len_a;i++){
        for(j=i+1;j<len_a;j++){
            if(p[i]<p[j]){
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
            if(a[i]<a[j]){
                ch=a[i];
                a[i]=a[j];
                a[j]=ch;
            }
        }
        if(p[i]!=a[i]-'0'){
            flag=0;
            break;
        }
    }
    if(flag==1){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    for(i=0;i<len_a;i++){
        printf("%d",c[i]);
    }
    return 0;
}
```
