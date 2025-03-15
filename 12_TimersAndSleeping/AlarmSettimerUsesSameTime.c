#define _GNU_SOURCE
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/time.h>

void timer_handler(int signal) {
    printf("Hello Your Timer Has Been Expired \n");
}

int main() {
    // ---------DEFINE TIMER TO SEND SIGALARMS AFTER 10 SECONDS---------
    struct itimerval timer;
    timer.it_value.tv_sec = 10; // 10 seconds
    timer.it_value.tv_usec = 0;

    timer.it_interval.tv_sec = 0; // donot repeat
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    // ---------DEFINE HANDLER FOR SIGALRM---------
    struct sigaction sa;
    sa.sa_handler = timer_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask); // donot block any signal
    sigaction(SIGALRM, &sa, NULL);

    // ---------OVERRIDE INITIAL TIMER WITH ALARM---------
    alarm(2); // send SIGALRM after 2 seconds

    pause();
    return 0;
}
