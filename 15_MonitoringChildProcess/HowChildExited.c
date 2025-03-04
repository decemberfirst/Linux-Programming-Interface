#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main() {
    pid_t pid = fork();
    if(pid == 0) {
        perror("fork");
        exit(1);
    }

    if(pid == 0) {
        // CHILD PROCESS
        printf("CHILD PROCESS: PID [%d]\n", getpid());
        sleep(5);
        exit(42); // 42 status code means child exited normally
    } else {
        // PARENT PROCESS
        int status ;
        pid_t child_pid = waitpid(pid, &status,0); // OPTIONS TAKE 0, WNOHANG, WUNTRACED
        if(child_pid > 0) {
            if(WIFEXITED(status)) { // WAIT IF EXITED
                printf("PARENT PROCESS: Child exited normally with status [%d]\n", WEXITSTATUS(status));
            } else if(WIFSIGNALED(status)) { // WAIT IF SIGNALED
                printf("PARENT PROCESS: Child exited abnormally with signal [%d]\n", WTERMSIG(status));
            } else if(WIFSTOPPED(status)) { // WAIT IF STOPPED
                printf("PARENT PROCESS: Child stopped with signal [%d]\n", WSTOPSIG(status));
            } else if(WIFCONTINUED(status)) { // WAIT IF CONTINUED
                printf("PARENT PROCESS: Child continued\n");
            }
        }
    }
    return 0;
}
