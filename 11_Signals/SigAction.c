#define _GNU_SOURCE
#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void handler(int sig) {
    printf("Interrupted\n");
    printf("Signal Number: %d\n", sig);

    // MAKE SIGNAL BUSY
    sleep(10);
}

int main() {

    struct sigaction sa;
    sa.sa_handler = handler;
    sa.sa_flags = SA_RESTART;
    // sigemptyset(&sa.sa_mask);
    sigfillset(&sa.sa_mask); // Block all signals while handling the current signal
    if(sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        return -1;
    }

    printf("Waiting for signals PID: %d\n", getpid());
    pause(); // pause process until signal is received
    return 0;
}
