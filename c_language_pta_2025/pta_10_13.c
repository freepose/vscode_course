
#include <stdio.h>

int main(void) {
    // 读入八进制字符串
    char s[100005];
    if (scanf("%100000s", s) != 1) return 0;

    // 用十进制大整数（低位在前）存结果
    // 若八进制长度为 n，则十进制位数约为 n*log10(8) < 0.91n
    int dec[100010] = {0};
    int len = 1; // 当前十进制位数（有效长度）

    for (char *p = s; *p; ++p) {
        int d = *p - '0'; // 当前八进制位
        int carry = d;
        for (int i = 0; i < len; ++i) {
            int tmp = dec[i] * 8 + carry;
            dec[i] = tmp % 10;
            carry = tmp / 10;
        }
        while (carry) {
            dec[len++] = carry % 10;
            carry /= 10;
        }
    }

    // 输出十进制（高位在前）
    for (int i = len - 1; i >= 0; --i) putchar('0' + dec[i]);
    putchar('\n');
    return 0;
}