#define _GNU_SOURCE
#include<stdio.h>
#include<sys/time.h>
#include<signal.h>

void signalHandler(int signo) {
    printf("Signal %d received\n", signo);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = signalHandler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);

    printf("Process ID: %d\n", getpid());
    unsigned int remaining_time = sleep(50); // sleep for 50 seconds

    printf("Remaining time: %d\n", remaining_time);
    return 0;
}
