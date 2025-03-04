#include <signal.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> // For waitpid()

#define CMD_SIZE 200

int main(int argc, char *argv[]) {
    char cmd[CMD_SIZE]; // For storing the command to be executed
    pid_t childPid;

    printf("Parent PID=%ld\n", (long)getpid());
    setbuf(stdout, NULL); // Disable buffering of stdout

    // Fork the process
    if ((childPid = fork()) == -1) {
        printf("fork failed\n");
        exit(EXIT_FAILURE);
    }

    if (childPid == 0) { // Child process
        printf("Child (PID=%ld) exiting\n", (long)getpid());
        _exit(EXIT_SUCCESS); // Exit the child process immediately
    }

    // Parent process
    sleep(3); // Give child a chance to start and exit

    // Print the process list, including the zombie process if it exists
    snprintf(cmd, CMD_SIZE, "ps -eo pid,stat,cmd | grep %s", basename(argv[0]));
    system(cmd); // Execute the command to check for zombie status

    // Now, let's kill the child process to leave it as a zombie
    kill(childPid, SIGKILL);
    sleep(1); // Give the child process some time to become a zombie

    printf("After sending SIGKILL to zombie (PID=%ld):\n", (long)childPid);
    snprintf(cmd, CMD_SIZE, "ps aux | grep 'Z' | grep %s", basename(argv[0]));
    system(cmd); // Check the status of the process again


    return 0;
}

/**
 * OUTPUT :
 * Parent PID=30563
Child (PID=30564) exiting
  30563 S+   ./Make_Zombie
  30564 Z+   [Make_Zombie] <defunct>
  30593 S+   sh -c -- ps -eo pid,stat,cmd | grep Make_Zombie
  30595 S+   grep Make_Zombie
After sending SIGKILL to zombie (PID=30564):
  30563 S+   ./Make_Zombie
  30564 Z+   [Make_Zombie] <defunct>
  30612 S+   sh -c -- ps -eo pid,stat,cmd | grep Make_Zombie
  30614 S+   grep Make_Zombie
 */
