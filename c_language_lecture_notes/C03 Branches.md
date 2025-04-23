# C03 ��֧�ṹ

## (1) ���ַ�֧�ṹ

    ��֧�ṹ�����֡�

### (a) ����֧�ṹ

�������⡣

```cpp
#include<stdio.h>

int main()
{
    float volume = -1;    // ��ˮ��

    scanf("%f", &volume);
    if (volume < 0)
    {
        volume = 0;
    }
    printf("water consumption is %.2f (ton)", volume);

    return 0;
}
```

### (b) ˫��֧�ṹ

��ˮ�ѡ�

```cpp
#include<stdio.h>

int main()
{
    float volume = -1, charge = 0.;    // ��ˮ��

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

### (c) ���֧�ṹ

����ˮ��

```cpp
#include<stdio.h>

int main()
{
    float volume = -1, charge = 0.;    // ��ˮ��

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
        printf("too much consumption! ȥ˰���");
    }

    printf("%.2f (ton) -> %.2f (rmb)", volume, charge);

    return 0;
}
```

```cpp
// 3-1 �ɼ�ת��
// ��������Ƴɼ�
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

### (d) �������

�����������switch��ʵ�֣����������䡣�ѵ���**case ��� break**��

```cpp
// ����ת��ȼ�
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

### ��Ŀ3-1 �ɼ�ת��

```cpp
#include<stdio.h>

int main()
{
    float score = 0.;    // ��ˮ��

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

### ��Ŀ3-2 ����ֶκ���[2]

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

### ��Ŀ3-3 ������ź�����ֵ

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

### ��Ŀ3-4 ����ƽ��С��

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

### ��Ŀ3-5 ���������������ܳ�

```cpp
#include <stdio.h>
```

### ��Ŀ3-6 �����ͷ�

### ��Ŀ3-7 �����������ɹ��

### ��Ŀ3-8 ��������С�������

### ��Ŀ3-9 �����������

### ��Ŀ3-10 ������

### ��Ŀ3-11 ���ʳ���

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

    // ������һ�����ʵĳ���
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

### ��Ŀ3-12 ��ż�ּ�

```cpp
#include <stdio.h>

int main() 
{
    int N;
    int odd_count = 0, even_count = 0;

    // ���� N
    scanf("%d", &N);

    // ���� N ��������ͳ����ż��
    for (int i = 0; i < N; i++) 
    {
        int num;
        scanf("%d", &num);

        // �ж�����������ż��
        if (num % 2 == 0) 
        {
            even_count++;  // ż��
        } else 
        {
            odd_count++;   // ����
        }
    }

    // ���������ż���ĸ���
    printf("%d %d\n", odd_count, even_count);

    return 0;
}
```

### ��Ŀ3-13 Ѱ��250

```cpp
#include <stdio.h>

int main() 
{
    int num;
    int index = 1;  // �ӵ�1�����ֿ�ʼ����

    // ��֪�������ж��ٸ����֣�����������ѭ��
    while (scanf("%d", &num) != EOF) 
    {
        if (num == 250) 
        {
            printf("%d\n", index);
            return 0;  // �ҵ����������
        }
        index++;  // �ƶ�����һ������
    }

    return 0;
}
```

### ��Ŀ3-14 ������

```cpp
#include <stdio.h>

int main() {
    int num;

    // ����һ��5λ��
    scanf("%d", &num);

    // ��ȡÿһλ����
    int digit1 = num / 10000;          // ��λ
    int digit2 = (num / 1000) % 10;   // ǧλ
    int digit4 = (num / 10) % 10;     // ʮλ
    int digit5 = num % 10;            // ��λ

    // �ж��Ƿ��ǻ�����
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

### ��Ŀ3-15 �������

```cpp
// ѭ����Ƿ����������
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

### ��Ŀ3-16 ͳ���ַ�

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

### ��Ŀ3-17 �������֤

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

### ��Ŀ3-18 ˭�ȵ�

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

### ��Ŀ3-19 ���GPLT

```cpp
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char input[10001]; // �����ַ�������󳤶�Ϊ10000

    // ��ȡ�����ַ���
    scanf("%s", input);

    // ���ڼ��� G, P, L, T �ĳ��ִ���
    int count[4] = {0}; // count[0] -> 'g', count[1] -> 'p', count[2] -> 'l', count[3] -> 't'

    // ͳ�Ƹ��ַ��ĸ����������ִ�Сд��
    for (int i = 0; input[i] != '\0'; i++)
    {
        char ch = tolower(input[i]); // ת��ΪСд�ַ�
        if (ch == 'g')
            count[0]++;
        else if (ch == 'p')
            count[1]++;
        else if (ch == 'l')
            count[2]++;
        else if (ch == 't')
            count[3]++;
    }

    // ���� GPLT ��˳������ַ���ֱ��ĳ���ַ�����
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

### ��Ŀ3-20 ����

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
