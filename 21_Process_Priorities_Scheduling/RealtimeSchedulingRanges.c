#include<sched.h>
#include<stdio.h>

int main() {
    int max = sched_get_priority_max(SCHED_RR);
    printf("The maximum priority is: %d\n", max); // returns maximum value that can be used with this policy

    int min = sched_get_priority_min(SCHED_RR); // returns minimum value that can be used with this policy
    printf("The minimum priority is: %d\n", min);
    return 0;
}
