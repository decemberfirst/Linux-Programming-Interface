#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<errno.h>

int main(int argc, char *argv[]) {
    int numChild = atoi(argv[1]);
    int numDead = 0;

    for(int i = 0; i < numChild; i++) {
        pid_t pid = fork();
        if(pid == 0) {
            printf("Child %d with PID %d\n", i, getpid());
            sleep(5);
            exit(0);
        }
    }

    while(numDead < numChild) {
        pid_t pid = wait(NULL);
        if(pid == -1) {
            if(errno == ECHILD) {
                printf("No more child to wait\n");
                break;
            } else {
                perror("wait");
            }
        }
        numDead++;
        printf("Child with PID %d has terminated\n", pid);
    }

    return 0;
}
