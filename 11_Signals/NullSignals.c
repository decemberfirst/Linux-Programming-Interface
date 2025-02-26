/**
 * NULL SIGNAL DOESNOT DO ANYTHING, BUT SOMETIMES IT IS USED TO CHECK
 * -> WE HAVE PERMISSION TO SEND SIGNAL TO THAT PROCESS OR NOT
 * -> THAT PROCESS EXISTS OR NOT
 */

#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <signal.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage %s PID \n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int status = kill(atoi(argv[1]), 0); // 0 MEANS NULL SIGNAL
    if (status == -1)
    {
        perror("signal");
        exit(EXIT_FAILURE);
    }

    printf("Signal Successfully sent ");
    return 0;
}
