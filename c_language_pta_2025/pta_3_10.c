#include <stdio.h>

int main()
{
    double speed, limit;

    scanf("%f %f", &speed, &limit);


    // 正常行驶：没有超出限速的10%
    if (speed < 1.1 * limit)
    {
        printf("OK\n");
    }
    else if (10. * speed < limit * 15)  
    {
        printf("Exceed %.0f%%. Ticket 200\n", 100.0 * (speed - limit) / limit);
    }
    else
    {
        printf("Exceed %.0f%%. License Revoked\n", 100.0 * (speed - limit) / limit);
    }

    return 0;
}