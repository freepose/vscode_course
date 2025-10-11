// #include <stdio.h>

// int main() 
// {
//     int number;
//     scanf("%d", &number); // 读取输入的四位数

//     // 提取每一位上的数字
//     int digit1 = number / 1000; // 千位
//     int digit2 = (number / 100) % 10; // 百位
//     int digit3 = (number / 10) % 10; // 十位
//     int digit4 = number % 10; // 个位

//     // 每一位上的数字加9，然后除以10取余
//     digit1 = (digit1 + 9) % 10;
//     digit2 = (digit2 + 9) % 10;
//     digit3 = (digit3 + 9) % 10;
//     digit4 = (digit4 + 9) % 10;

//     // 交换千位和十位，百位和个位
//     int encryptedNumber = digit3 * 1000 + digit4 * 100 + digit1 * 10 + digit2;

//     // 输出加密后的数，确保保留前导零
//     printf("The encrypted number is %04d\n", encryptedNumber);

//     return 0;
// }


// From 黄宇灵 2025级

#include <stdio.h>

int main()
{
    int x;
    scanf("%d", &x);

    int arr[4];

    for (int i = 0; i < 4; i++)
    {
        arr[i] = x % 10;
        x = x / 10;
        arr[i] = (arr[i] + 9) % 10;
    }

    int temp = 0;
    temp = arr[1];
    arr[1] = arr[3];
    arr[3] = temp;

    temp = arr[2];
    arr[2] = arr[0];
    arr[0] = temp;

    int result = arr[0] + arr[1] * 10 + arr[2] * 100 + arr[3] * 1000;
    printf("The encrypted number is %04d", result);

    return 0;
}
