#include<stdio.h>
#include<sys/resource.h>
#include<sched.h>

/**
 * WHO TAKES THESE VALUES:
 * RUSAGE_SELF: The resources used by the current process.
 * RUSAGE_CHILDREN: The resources used by the child processes of the current process.
 * RUSAGE_THREAD: The resources used by the threads of the current process.
 */

int main() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);

    printf("Time elapsed in user mode: %ld.%06ld seconds\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
    printf("Time elapsed in kernel mode: %ld.%06ld seconds\n", usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
     // denotes maximum amount of ram used by the process at any time during its execution
    printf("Maximum resident set size in MB: %ld\n", usage.ru_maxrss / 1024); // default return value is in KB
    printf("Shared text memory size: %ld\n", usage.ru_ixrss); // ignored in linux
    printf("Unshared data size: %ld\n", usage.ru_idrss); // ignored in linux
    printf("Unshared stack size: %ld\n", usage.ru_isrss); // ignored in linux

     // number of page faults that could be resolved without disk I/O
    printf("Soft page faults: [CACHE HITS] %ld\n", usage.ru_minflt);
    // number of page faults that required disk I/O
    printf("Hard page faults: [CACHE MISSES] %ld\n", usage.ru_majflt);

    printf("Number of times memory was swapped out: %ld\n", usage.ru_nswap); // ignored in linux
    printf("Number of Block input operations: %ld\n", usage.ru_inblock);
    printf("Number of Block output operations: %ld\n", usage.ru_oublock);

    for(int i=0; i<100000000; i++) {
       // simulate to get context switch
    }

    printf("Number of voluntary context switches: %ld\n", usage.ru_nvcsw);
    printf("Number of involuntary context switches: %ld\n", usage.ru_nivcsw);

    printf("Number of signals received: %ld\n", usage.ru_nsignals);
    // IPC
    printf("Number of messages sent: %ld\n", usage.ru_msgsnd);
    printf("Number of messages received: %ld\n", usage.ru_msgrcv);
    return 0;
}
