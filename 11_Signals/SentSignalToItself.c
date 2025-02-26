#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void custom_handler(int signal)
{
    printf("SIGINT signal got by the process ...\n");
}

int main()
{
    signal(SIGINT, custom_handler);
    raise(SIGINT); // RAISE SIGNAL TO ITSELF
    return 0;
}
