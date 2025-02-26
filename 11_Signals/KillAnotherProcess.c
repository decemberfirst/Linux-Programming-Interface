#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 1)
    {
        printf("Usage %s PID", argv[0]);
        exit(EXIT_FAILURE);
    }

    /**
     * If pid > 0: The signal is sent to the process with the specified process ID (pid)
     * If pid = 0: The signal is sent to all processes in the same process group, including the calling process itself.
     * If pid < -1: The signal is sent to all processes in the process group whose ID is the absolute value of pid.
     * If pid = -1: The signal is sent to all processes the calling process can send signals to, except for the init process (process ID 1) and itself. If the calling process has special privileges, it can send signals to all processes on the system, excluding these two. This is called a broadcast signal.
     */
    kill(atoi(argv[1]), SIGINT);
    return 0;
}
