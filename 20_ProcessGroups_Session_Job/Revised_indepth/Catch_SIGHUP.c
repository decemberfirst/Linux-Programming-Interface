#define _GNU_SOURCE
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

static void handler(int sig) {

}

int main(int argc, char *argv[]) {
    pid_t childPid;
    struct sigaction sa;
    setbuf(stdout, NULL);

    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if(sigaction(SIGHUP, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    childPid = fork();
    if(childPid == -1) {
        perror("fork");
        return 1;
    }

    if(childPid ==0 && argc > 1) {
        printf("inside child process\n");
        if(setpgid(0, 0) == -1) {
            perror("setpgid");
            return 1;
        }
    }

    printf("PID=%ld; PPID=%ld; PGID=%ld; SID=%ld\n", (long)getpid(), (long)getppid(), (long)getpgrp(), (long)getsid(0));

    alarm(60); // this ensures the child process will exit eventually
    for(;;) {
        pause();
        printf("%ld: caught SIGHUP\n", (long)getpid());
    }
    return 0;
}
