#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main() {
    pid_t pid = fork();
    if(pid > 0) {
        // parent process
        printf("Parent process pid=%ld\n", (long)getpid());
        printf("Parent process group id=%ld\n", (long)getpgrp());
        printf("Parent session id=%ld\n", (long)getsid(0));
        _exit(EXIT_SUCCESS);
    }

    if(setsid() == -1) {
        perror("setsid");
        exit(EXIT_FAILURE);
    }

    printf("PID=%ld, PGID=%ld, SID=%ld\n", (long)getpid(), (long)getpgrp(), (long)getsid(0));
    if(open("/dev/tty", O_RDWR) == -1) { // throws error, because controlling terminal is removed by setsid
        perror("open");
        exit(EXIT_FAILURE);
    }

    return 0;
}
