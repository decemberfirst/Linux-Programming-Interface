#include<stdio.h>
#include<sched.h>

int main() {
    struct timespec interval;
    sched_rr_get_interval(0, &interval);

    printf("Time quantum in seconds: %ld\n", interval.tv_sec);
    printf("Time quantum in milliseconds: %ld\n", interval.tv_nsec / 1000000 ); // 3ms
    return 0;
}
