#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void timer_handler(int signal)
{
    printf("Hello Your Timer Has Been Expired \n");
}

int main()
{
    signal(SIGALRM, timer_handler);
    alarm(5); // send SIGALRM after 5 seconds
    pause();
    return 0;
}
