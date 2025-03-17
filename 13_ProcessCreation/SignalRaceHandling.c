#define _GNU_SOURCE
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SYNC_SIGNAL SIGUSR1 // USER DEFINED SIGNAL

void handler(int sig) {
    // The handler can now execute and process the signal.
}

int main() {
    pid_t pid;
    sigset_t emptyMask;
    struct sigaction sa;

    // Initialize signal action
    sa.sa_handler = handler;
    sa.sa_flags = SA_RESTART;
    sigemptyset(&sa.sa_mask);           // Set up an empty signal mask
    sigaddset(&sa.sa_mask, SYNC_SIGNAL); // Block SYNC_SIGNAL while the handler is executing
    sigaction(SYNC_SIGNAL, &sa, NULL);

    switch( pid = fork()) {
        case -1:
            perror("fork");
            exit(EXIT_FAILURE);
        case 0:
            printf("Child doing some work\n");
            sleep(2);
            printf("Child sending signal\n");
            kill(getppid(), SYNC_SIGNAL);
            _exit(EXIT_SUCCESS);
        default:
            printf("Parent waiting for signal\n");
            sigemptyset(&emptyMask);
            sigsuspend(&emptyMask); // sig suspend temporarily replaces the signal mask of the calling process with the emptyMask
            printf("Parent got signal\n");
            exit(EXIT_SUCCESS);
    }

    return 0;
}
