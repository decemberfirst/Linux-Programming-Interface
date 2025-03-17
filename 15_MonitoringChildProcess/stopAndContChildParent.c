#define _GNU_SOURCE
#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main() {
    pid_t pid;
    pid = fork();
    if(pid == 0) {
        printf("Child is running with PID: %d\n", getpid());
        sleep(5);
        printf("raised the stop signal\n");
        raise(SIGSTOP); // STOP THE EXECUTION, UNTIL PARENT SENDS CONTINUE SIGNAL
        printf("Child is running again after sigstop\n");
        _exit(0);
    } else {
        printf("Parent is running with PID: %d\n", getpid());
        waitpid(pid, NULL, WUNTRACED);// WAIT FOR CHILD TO STOP
        sleep(2);
        kill(pid, SIGCONT); // CONTINUE THE CHILD PROCESS
        printf("Sent continue signal to child\n");
        // see here it is 0, it means wait until child process is terminated
        waitpid(pid, NULL, 0); // WAIT FOR CHILD TO TERMINATE, BECAUSE IT IS RESUMED AGAIN
        printf("Child terminated\n");
        printf("Parent terminated\n");
    }
    return 0;
}
