#include <stdio.h>
#include <time.h>

int main()
{
    time_t currentTime = time(NULL);
    printf("The Current time is %ld\n", currentTime);
    return 0;
}
