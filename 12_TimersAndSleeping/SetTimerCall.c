#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

/**
 * THREE WHICH VALUES
 *  - ITIMER_REAL -> REAL CLOCK TIME, DECREMENTS IN REAL TIME, SENDS SIGALARM
 *  - ITIMER_VIRTUAL -> VIRTUAL CLOCK TIME, DECREMENTS ONLY WHEN THE PROCESS IS RUNNING, SENDS SIGVTALARM
 * - ITIMER_PROF -> PROFILE CLOCK TIME, DECREMENTS ONLY WHEN THE PROCESS IS RUNNING AND DURING SYSCALL, SENDS SIGPROF
 */

// default disposition is to terminate the process

// new_value -> struct itimerval { struct timeval it_interval; struct timeval it_value; }
// old_value -> points to the previous value of the timer
/**
 * struct itimerval {
    struct timeval it_interval;  // Interval for periodic timer
    struct timeval it_value;     // Time until next expiration
};

struct timeval {
    time_t tv_sec;   // Seconds
    suseconds_t tv_usec; // Microseconds
};
 */
void timer_handler(int signal)
{
    printf("Hello Your Timer Has Been Expired \n");
}

int main()
{
    signal(SIGALRM, timer_handler);
    struct itimerval timer;
    timer.it_value.tv_sec = 5; // initial delay
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 2; // interval time
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    while (1)
    {
        pause(); // pause the process until a first signal is received
    }
    return 0;
}
