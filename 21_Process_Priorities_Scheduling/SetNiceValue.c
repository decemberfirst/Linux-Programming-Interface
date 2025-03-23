#include<stdio.h>
#include<sys/resource.h>

// NOTICE: YOU NEED TO RUN THIS PROGRAM AS ROOT USER

int main() {
    int which = PRIO_PROCESS; // OPERATE ON PROCESS
    int who = 0; // USE CALLER ID THAT IS SAME AS CALLING GETPID()
    int result = setpriority(which, who, -20); // goes from -20 to 19
    if(result == 0) {
        printf("Priority set successfully\n");
    } else {
        printf("Failed to set priority\n");
    }
    return 0;
}
