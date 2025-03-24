#include<stdio.h>
#include<sched.h>

int main() {
    struct sched_param priority;
    int policy = sched_getscheduler(0); // 0 is the caller
    int param = sched_getparam(0, &priority); // 0 is the caller

    if(policy == -1 || param == -1) {
        perror("sched_getscheduler/sched_getparam");
        return 1;
    }

    if(policy == SCHED_FIFO) {
        printf("Scheduler is SCHED_FIFO with priority %d\n", priority.sched_priority);
    } else if(policy == SCHED_RR) {
        printf("Scheduler is SCHED_RR with priority %d\n", priority.sched_priority);
    } else if(policy == SCHED_OTHER) {
        printf("Scheduler is SCHED_OTHER with priority %d\n", priority.sched_priority);
    } else {
        printf("Scheduler is unknown with priority %d\n", priority.sched_priority);
    }

    return 0;
}
