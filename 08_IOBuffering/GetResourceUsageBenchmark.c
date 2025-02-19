#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
/*
    THIS PROGRAM SHOWS HOW MUCH PARTICULAR CODE TOOK IN USER MODE AND KERNEL MODE RESPECTIVELY ...
*/
int main()
{
    struct rusage usage;

    for (volatile long i = 0; i < 1; i++)
        ;

    getrusage(RUSAGE_SELF, &usage);

    float userTime = (float)(usage.ru_utime.tv_sec) * 1000 + (float)(usage.ru_utime.tv_usec) / 1000;
    float systemTime = (float)(usage.ru_stime.tv_sec) * 1000 + (float)(usage.ru_stime.tv_usec) / 1000;

    printf("User Time: %.3f ms\n", userTime);
    printf("System Time: %.3f ms\n", systemTime);

    return 0;
}
