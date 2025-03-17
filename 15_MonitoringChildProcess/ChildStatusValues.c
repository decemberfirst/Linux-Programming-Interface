#define _GNU_SOURCE
#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main() {
    pid_t pid;
    int returnStatus;
    pid = fork();
    if(pid == 0) {
        printf("Child is running with PID: %d\n", getpid());
        printf("Child is slept now for 2 seconds\n");
        sleep(20);
        printf("Child is running again after 2 seconds\n");
    } else {
        printf("Parent is running with PID: %d\n", getpid());
        waitpid(pid, &returnStatus, WUNTRACED);

        if(WIFEXITED(returnStatus)) {
            printf("Child exited normally with status: %d\n", WEXITSTATUS(returnStatus));
        } else if (WIFSIGNALED(returnStatus)) {
            printf("Child exited due to signal with status: %d\n", WTERMSIG(returnStatus));
        } else if (WIFSTOPPED(returnStatus)) {
            printf("Child stopped due to signal with status: %d\n", WSTOPSIG(returnStatus));
        } else if (WIFCONTINUED(returnStatus)) {
            printf("Child continued\n");
        }
    }
}
