

// ��2-4���ֶκ����� �쳣ֵ���� -> ��֧��� -> �ֶ�ˮ��

#include <stdio.h>

int main()
{
    float fahr = 25, celsius;

    if (fahr > -273)    // ����¶���������������¶�ת��
    {
        celsius = 5. * (fahr - 32) / 9;
        printf("%.2f��F -> %.2f��C ", fahr, celsius);
    }
    else                // �������������Ϣ
    {    
        printf("Error: Temperature below absolute zero.\n");
    }

    return 0;
}
