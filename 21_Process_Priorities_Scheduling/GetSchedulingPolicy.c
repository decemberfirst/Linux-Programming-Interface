#include<stdio.h>
#include<sched.h>

int main() {
    int policy = sched_getscheduler(0); // 0 is the caller
    if(policy == -1) {
        perror("sched_getscheduler");
        return 1;
    }

    if(policy == SCHED_FIFO) {
        printf("Scheduler is SCHED_FIFO\n");
    } else if(policy == SCHED_RR) {
        printf("Scheduler is SCHED_RR\n");
    } else if(policy == SCHED_OTHER) {
        printf("Scheduler is SCHED_OTHER\n");
    } else {
        printf("Scheduler is unknown\n");
    }
    return 0;
}
