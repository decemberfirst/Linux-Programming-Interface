#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

static int cmdNum;  // Position in the pipeline

// Signal handler function
static void handler(int sig)
{
    // Check if this process is the leader of the process group
    if (getpid() == getpgrp())
        fprintf(stderr, "Foreground Process Group ID (from terminal): %ld\n", (long) tcgetpgrp(STDERR_FILENO));

    // Print the process details when a signal is received
    fprintf(stderr, "Process %ld (Position %d) received signal %d\n", (long) getpid(), cmdNum, sig);

    // If the signal is SIGTSTP, stop the process by sending SIGSTOP
    if (sig == SIGTSTP)
        raise(SIGSTOP);
}

int main(int argc, char *argv[])
{
    struct sigaction sa;
    sigemptyset(&sa.sa_mask);   // Initialize the signal mask to be empty
    sa.sa_flags = SA_RESTART;   // Set flags to restart interrupted system calls
    sa.sa_handler = handler;    // Set the signal handler

    // Install signal handlers for SIGINT, SIGTSTP, and SIGCONT
    if (sigaction(SIGINT, &sa, NULL) == -1)
        perror("Error setting SIGINT handler");

    if (sigaction(SIGTSTP, &sa, NULL) == -1)
        perror("Error setting SIGTSTP handler");

    if (sigaction(SIGCONT, &sa, NULL) == -1)
        perror("Error setting SIGCONT handler");

    // Check if this is the first process in the pipeline
    if (isatty(STDIN_FILENO)) {
        // If it's the first process, print the terminal's foreground process group ID
        fprintf(stderr, "Foreground Process Group ID of the Terminal: %ld\n", (long) tcgetpgrp(STDIN_FILENO));

        // Print the header for process information
        fprintf(stderr, "Process Position  PID  PPID  PGRP  SID\n");

        cmdNum = 0;  // Set the position to 0 for the first process
    } else {
        // If not the first process, read the position from the previous process
        if (read(STDIN_FILENO, &cmdNum, sizeof(cmdNum)) <= 0)
            perror("Error reading from pipe");
    }

    cmdNum++;  // Increment the position as this process is now assigned its position in the pipeline

    // Print process details: position, PID, PPID, process group ID, and session ID
    fprintf(stderr, "Position: %d, PID: %ld, PPID: %ld, PGRP: %ld, SID: %ld\n", cmdNum,
            (long) getpid(), (long) getppid(), (long) getpgrp(), (long) getsid(0));

    // If this is not the last process, pass the message (pipeline position) to the next process
    if (!isatty(STDOUT_FILENO)) {
        // If the standard output is not a terminal (i.e., this is not the last process), write the position to the pipe
        if (write(STDOUT_FILENO, &cmdNum, sizeof(cmdNum)) == -1)
            perror("Error writing to pipe");
    }

    // Infinite loop to wait for signals
    for(;;)
        pause();  // This makes the process wait until a signal is received
}
