#define _GNU_SOURCE
#include<stdio.h>
#include<sched.h>

int main() {
    cpu_set_t setMask;
    CPU_ZERO(&setMask);
    CPU_SET(5, &setMask); // Set CPU 0 for the process
   int ret =  sched_setaffinity(0, sizeof(cpu_set_t), &setMask);
    if(ret == -1) {
         perror("sched_setaffinity");
    }

    printf("Process is running on CPU: %d\n", sched_getcpu());
    while(1);
    return 0;
}
