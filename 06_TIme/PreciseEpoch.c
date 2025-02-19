#include <stdio.h>
#include <sys/time.h>

int main()
{
    struct timeval *val;
    gettimeofday(val, NULL);
    printf("Seconds : %ld\n", val->tv_sec);
    printf("Millisecond : %ld\n", val->tv_usec);
    return 0;
}
