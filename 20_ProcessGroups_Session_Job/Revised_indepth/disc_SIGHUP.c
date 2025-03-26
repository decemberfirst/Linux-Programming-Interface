#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>

static void handler(int sig) {
    printf("PID %ld: caught signal %d (%s)\n", (long)getpid(), sig, strsignal(sig));
}

int main(int argc, char *argv[]) {
    pid_t parentPid, childPid;
    struct sigaction sa;

    if(argc < 2) {
        fprintf(stderr, "Usage: %s <command>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    setbuf(stdout, NULL);
    parentPid = getpid();

    printf("PID of parent process is: %ld\n", (long) parentPid);
    printf("Foreground process group id is: %ld\n", (long) tcgetpgrp(STDIN_FILENO));

    for(int j=1; j<argc; j++) {
        childPid = fork();

        if(childPid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if(childPid == 0) {
            if(argv[j][0] == 'd') {
                // if d is specified , set child in different process group
                if(setpgid(0, 0) == -1) {
                    perror("setpgid");
                    exit(EXIT_FAILURE);
                }
            }

            // setup sighup handler
            sigemptyset(&sa.sa_mask);
            sa.sa_flags = 0;
            sa.sa_handler = handler;

            if(sigaction(SIGHUP, &sa, NULL) == -1) {
                perror("sigaction");
                exit(EXIT_FAILURE);
            }

            break;
        }
    }

    alarm(60);
    printf("PID=%ld PGID=%ld\n", (long) getpid(), (long) getpgrp());
    for(;;) {
        pause();
    }
    return 0;
}
