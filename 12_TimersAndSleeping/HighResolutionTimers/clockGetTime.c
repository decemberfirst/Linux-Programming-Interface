#define _GNU_SOURCE
#include <stdio.h>
#include <time.h>

int main()
{
    struct timespec start, end;
    clock_gettime( CLOCK_MONOTONIC, &start);

    for (int i = 0; i < 10000000; i++)
    {
        // simulate some work
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    // 1s -> 1,000,000,000 ns
    long elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000 + end.tv_nsec - start.tv_nsec;
    printf("Time taken: %ld ns\n", elapsed_ns);
    return 0;
}
