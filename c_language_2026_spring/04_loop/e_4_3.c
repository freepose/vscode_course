
#include <stdio.h>

int main()
{
    char sex;
    int height, weight;
    int users = 3;

    for (int i = 1; i <= users; i++)
    {
        // 输入：性别和身高（cm），输出：标准体重（kg）
        // if (scanf(" %c %d", &sex, &height) != 2)
        // {
        //     break;
        // }
        scanf(" %c %d", &sex, &height);

        if (sex == 'F' || sex == 'f')
        {
            weight = height - 105;
        }
        else
        {
            weight = height - 100;
        }
        printf("Standard weight: %d kg\n", weight);
    }

    

    return 0;
}