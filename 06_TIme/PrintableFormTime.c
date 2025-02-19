#include <stdio.h>
#include <time.h>
// 26 bytes fixed format string
int main()
{
    time_t currEpoch = time(NULL);
    char *printableTime = ctime(&currEpoch);
    printf("%s", printableTime);
    return 0;
}
