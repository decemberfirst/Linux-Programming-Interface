#include <stdio.h>
#include <time.h>

int main()
{
    time_t currentEpoch = time(NULL);
    struct tm *brokenDown = localtime(&currentEpoch);
    printf("Broken down time details: \n");
    printf("Year: %d\n", brokenDown->tm_year + 1900); // gives year since 1900 hence add
    printf("Month %d \n", brokenDown->tm_mon);
    printf("Day %d \n", brokenDown->tm_mday);
    printf("Week Day %d\n", brokenDown->tm_wday);
    return 0;
}
