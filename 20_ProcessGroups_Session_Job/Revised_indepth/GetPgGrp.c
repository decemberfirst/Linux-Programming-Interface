#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main() {
    pid_t pid = getpgrp();
    if(pid == getpid()) {
        printf("This process is a process group leader\n");
    } else {
        printf("Leader is any other process\n");
    }
    return 0;
}
