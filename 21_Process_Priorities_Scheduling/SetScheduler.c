#include<stdio.h>
#include<sched.h>

int main() {
    int policy = SCHED_RR;
    struct sched_param priority;
    priority.sched_priority = sched_get_priority_max(policy);
    int ret = sched_setscheduler(0, policy, &priority); // 0 is the caller

    if(ret == -1) {
        perror("sched_setscheduler");
        return 1;
    }

    printf("Scheduler set to SCHED_RR with priority %d\n", priority.sched_priority);
    return 0;
}
