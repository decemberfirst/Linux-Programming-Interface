#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main() {
    pid_t childPID = fork();

    if(childPID == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if(childPID == 0) {
        sleep(5); // allow parent to exit first
        printf("The Parent Process Id Of this Child Process is %d\n", getppid());
        fflush(stdout);
        _exit(0);
    } else {
        printf("The parent process id is %d\n", getpid());
        printf("The child process id is %d\n", childPID);
        exit(EXIT_SUCCESS);
    }
    return 0;
}
