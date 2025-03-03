#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main() {
    printf("Hello, World \n");
    write(STDOUT_FILENO, "NAMASTE\n", 8);

    pid_t childPID = fork();
    if(childPID == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if(childPID == 0) {
        _exit(EXIT_SUCCESS); // it doesnot flush the stdio buffers
    }

    exit(EXIT_SUCCESS);

}
