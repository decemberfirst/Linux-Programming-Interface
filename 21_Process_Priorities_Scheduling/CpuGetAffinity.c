#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <stdlib.h> // For exit()

int main() {
    cpu_set_t setMask;
    CPU_ZERO(&setMask);

    // Error handling for sched_getaffinity
    if (sched_getaffinity(0, sizeof(cpu_set_t), &setMask) == -1) {
        perror("sched_getaffinity failed");
        return 1;
    }

    for (long i = 0; i < sysconf(_SC_NPROCESSORS_ONLN); i++) {
        if (CPU_ISSET(i, &setMask)) {
            printf("CPU: %ld\n", i); // by default all cores are set
        }
    }

    while (1);
    return 0;
}
