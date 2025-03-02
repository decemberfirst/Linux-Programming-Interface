/**
 * in vfork parent is suspended until child calls exec or exit
 * child process shares the address space of parent until exec or exit
 */

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main() {
    int isStack = 100;
    pid_t child = vfork();

    if(child == -1) {
        perror("fork");
        exit(1);
    }

    if(child == 0) { // child process
            sleep(3); // sleep for 3 seconds
            write(STDOUT_FILENO, "Child process\n", 14);
            isStack = 200;
            _exit(0);
    }

    // parent process
    write(STDOUT_FILENO, "Parent process\n", 15);
    printf("Is stack value in parent is %d\n", isStack);
    return 0;
}
