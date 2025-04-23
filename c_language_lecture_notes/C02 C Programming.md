# C02 ��C����д����

> ǧ��֮�У�ʼ�����¡�

��Ҫע��ı��ϰ�ߣ�ע���Сд��ע����Ӣ�ģ�ע��������ע��ֺţ�ע�⻻�С�

��˫�ɶԣ��������ϸ�ڡ�

�ؼ����������⣬�ؼ���Ҫ���ñ�

## (1) ��������

��2-1������Ļ����ʾһЩ��Ϣ

```cpp
// The "Hello, World!" program for c beginners.

#include<stdio.h>

int main()
{
    printf("Hello World!");
    return 0;
}
```

С�ᣬ����main����������printf�������Լ����õ�ͷ�ļ���

ϰ�ߣ���˫�ɶԣ�ע�����������ʽ��̡�

��2-3�������¶�100��F ��Ӧ�������¶�

```cpp
#include <stdio.h>

int main()
{
    /* �����������ͱ�����celsius��ʾ��?�ȣ�fahr��ʾ��?�� */
    int celsius, fahr;

    /* ��?��?�ڷָ���������Ϳ�ִ?��� */
    fahr = 100;                    /* �Ա���fahr ��ֵ*/
    celsius = 5 * (fahr - 32) / 9; /* �¶�ת������*/

    printf("fahr = %d, celsius = %d\n", fahr, celsius);

    return 0;
}
```

С�ᣬ���ܱ������������͡���ʽ���������Ƶ�����ʽ�����������㣬�����

��2-4���ֶμ���ˮ�ѡ�

```cpp
// �ֶκ�������
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

С�ᣬ����scanf�������Լ�if ... else...���÷���

## (2) Pintia

### ��Ŀ2-1 Hello World!

```cpp
#include<stdio.h>

int main()
{
    printf("Hello World!");
    return 0;
}
```

### ��Ŀ2-2 Say Hello to Integers

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

### ��Ŀ2-3 ��Բ�ܳ�

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

### ��Ŀ2-4 ������

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

### ��Ŀ2-5 ���������ͼ��

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

### ��Ŀ2-6 �������λ��

����˼·��(1) ͨ�����෽ʽ�����Զ������ض�λ����(2) ��������10���Լ�ȥ���һλ����

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

### ��Ŀ2-7 ����������ݸ�ʽ������

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

### ��Ŀ2-8 ��������Ϣ

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

### ��Ŀ2-9 ���ڸ�ʽ��

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

### ��Ŀ2-10 ���������ʱ��

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