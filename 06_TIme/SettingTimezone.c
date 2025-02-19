#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    setenv("TZ", "Asia/Kolkata", 1); // extract timezone info from /usr/share/zoneinfo
    tzset();
    time_t currentEpoch = time(NULL);
    printf("The Current Time According to TZ is: %s", ctime(&currentEpoch));
    return 0;
}
