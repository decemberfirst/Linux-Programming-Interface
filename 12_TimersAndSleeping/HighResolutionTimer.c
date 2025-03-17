#define _GNU_SOURCE
#include <stdio.h>
#include<time.h>

// CLOCK_REALTIME GIVES EPOCH TIME WITH NANOSECOND PRECISION
// CLOCK MONOTONIC GIVES TIME SINCE BOOT WITH NANOSECOND PRECISION
// CLOCK_PROCESS_CPUTIME_ID GIVES TIME SPENT BY PROCESS IN USER AND KERNEL MODE
// CLOCK_THREAD_CPUTIME_ID GIVES TIME SPENT BY THREAD IN USER AND KERNEL MODE

int main() {
    struct timespec startTime;
    // // clock_gettime(CLOCK_REALTIME, &startTime);
    // time_t epoch = time(NULL);
    // printf("Epoch Time: %ld\n", epoch);
    // printf("Epoch with nanosecond precision %ld.%09ld\n", startTime.tv_sec, startTime.tv_nsec);

    // clock_gettime(CLOCK_MONOTONIC, &startTime);
    // printf("MONOTONIC Time: %ld.%09ld\n", startTime.tv_sec, startTime.tv_nsec);

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &startTime);
    printf("PROCESS CPU Time: %ld.%09ld\n", startTime.tv_sec, startTime.tv_nsec);

    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &startTime);
    printf("THREAD CPU Time: %ld.%09ld\n", startTime.tv_sec, startTime.tv_nsec);
    return 0;
}
