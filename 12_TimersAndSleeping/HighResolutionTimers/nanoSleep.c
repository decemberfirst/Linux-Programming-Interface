#include <stdio.h>
#include <time.h>

int main()
{
    struct timespec sleepTime;
    sleepTime.tv_nsec = 100000000; // 100ms
    sleepTime.tv_sec = 0;
    nanosleep(&sleepTime, NULL);
    printf("Slept for 100ms\n");
    return 0;
}
