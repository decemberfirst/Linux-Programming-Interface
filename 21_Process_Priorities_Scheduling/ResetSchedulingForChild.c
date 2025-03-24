#define _GNU_SOURCE
#include<stdio.h>
#include<sched.h>
#include<unistd.h>


int main() {
    int policy = SCHED_FIFO;
    struct sched_param param;
    param.sched_priority = 99;

    // reset on fork
    policy |= SCHED_RESET_ON_FORK;
    int success =  sched_setscheduler(getpid(), policy, &param);

   if(success == -1) {
       perror("sched_setscheduler");
       return -1;
   }

   printf("Scheduling policy set to SCHED_FIFO for parent\n");
   printf("[PARENT]\n");
   int parentPolicy = sched_getscheduler(getpid());
   if(parentPolicy == SCHED_FIFO) {
       printf("Parent policy is SCHED_FIFO\n");
   }

   setbuf(stdout, NULL);

   pid_t pid = fork();
   if(pid == -1) {
       perror("fork");
       return -1;
   }

   if(pid == 0) {
    printf("[CHILD]\n");
    int childPolicy = sched_getscheduler(getpid());
    if(childPolicy == SCHED_FIFO) {
        printf("Child policy is SCHED_FIFO\n");
    } else if(childPolicy == SCHED_OTHER) {
        printf("Child policy is SCHED_OTHER\n");
    } else if(childPolicy == SCHED_RR) {
        printf("Child policy is SCHED_RR\n");
    }

    _exit(0);
   }


    return 0;
}
