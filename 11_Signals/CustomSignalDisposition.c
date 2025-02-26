#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void custom_handler(int signal)
{
    printf("GOT SIGINT signal %d\n", signal);
}

void custom_sigterm_handler(int signal)
{
    printf("GOT SIGTERM SIGNAL: %d \n", signal);
}

int main()
{
    printf("Waiting for the signal from the user ...\n");
    signal(SIGINT, custom_handler);
    signal(SIGTERM, custom_sigterm_handler);
    while (1)
    {
    }
    return 0;
}
