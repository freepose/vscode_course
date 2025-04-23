
#include <stdio.h>

int main()
{
    int start, end, duration, hour, minute;
    int start_hour, start_minute, end_hour, end_minute;

    scanf("%d %d", &start, &end);

    start_hour = start / 100;
    start_minute = start % 100;

    end_hour = end / 100;
    end_minute = end % 100;

    start = start_hour * 60 + start_minute; // turn time into minutes
    end = end_hour * 60 + end_minute;    // turn time into minutes

    duration = end - start;
    hour = duration / 60;
    minute = duration % 60;

    printf("%02d:%02d\n", hour, minute);

    return 0;
}