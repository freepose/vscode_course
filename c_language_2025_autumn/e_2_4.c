

// ��2-4���ֶκ����� �쳣ֵ���� -> ��֧��� -> �ֶ�ˮ�ѣ�*��

#include <stdio.h>

int main()
{
    float charge, volume = 20;

    scanf("%f", &volume);   // ע��&Ϊȡ��ַ��

    if (volume < 0)
    {
        printf("Error: Volume cannot be negative.\n");
    }
    else if (volume <= 15)
    {
        charge = volume * 4.0 / 3;
        printf("volume = %.2f, charge = %.2f\n", volume, charge);
    }
    else
    {
        charge = - 10.5 + 2.5 * volume ;
        printf("volume = %.2f, charge = %.2f\n", volume, charge);
    }  

    return 0;
}
