#define _GNU_SOURCE
#include<stdio.h>
#include<sys/time.h>
#include<signal.h>

void myAlarmHandler(int sig) {
    printf("Alarm Signal Received\n");
}

int main() {
    struct itimerval timer;
    struct sigaction sa;

    sa.sa_handler = myAlarmHandler;
    sa.sa_flags = SA_RESTART;
    sigemptyset(&sa.sa_mask);

    if(sigaction(SIGALRM, &sa, NULL) == -1) {
        perror("sigaction");
        return -1;
    }

    timer.it_value.tv_sec = 5; // initial 5 sec delay
    timer.it_value.tv_usec = 500; // total 5.5 sec delay

    timer.it_interval.tv_sec = 1; // interval of 1 sec, repeat after each 1 sec after first signal
    timer.it_interval.tv_usec = 0;


    setitimer(ITIMER_REAL, &timer,NULL);

    while(1) {
        pause(); // this waits for one signal to be received only, hence we need to call it again through loop
    }

    return 0;
}
