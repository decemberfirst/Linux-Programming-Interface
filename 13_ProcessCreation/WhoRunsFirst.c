#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>

/**
 * CHILD FIRST RATIO: 0.03%
 * PARENT FIRST RATIO: 99.97%
 */

int main(int argc, char *argv[]) {
    int numChildren = argc > 1 ? atoi(argv[1]) : 1;
    for(int i=0; i<numChildren; i++) {
        pid_t childPID = fork();
        if(childPID == -1) {
            perror("fork");
            exit(1);
        }

        if(childPID == 0) {
            printf("Child process %d\n", i);
            exit(0);
        } else {
            printf("Parent process %d\n", i);
            wait(NULL);
        }
    }
    return 0;
}
