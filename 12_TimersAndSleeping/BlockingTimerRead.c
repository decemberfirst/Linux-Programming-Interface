#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>

void handle_alarm(int sig)
{
    printf("\nTimeout! Read operation interrupted.\n");
    exit(0);
}

int main()
{

    signal(SIGALRM, handle_alarm);

    alarm(5);

    char buffer[100];
    printf("Enter something within 5 seconds: ");
    fflush(stdout);

    if (read(STDIN_FILENO, buffer, sizeof(buffer)) == -1)
    {
        if (errno == EINTR)
        {
            printf("Read operation timed out!\n");
        }
        else
        {
            perror("read");
        }
    }
    else
    {
        printf("You entered: %s", buffer);
    }

    alarm(0);

    return 0;
}
