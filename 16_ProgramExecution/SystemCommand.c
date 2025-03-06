/*
The system() function creates a child process that invokes a shell to execute
command. Here is an example of a call to system():
 */
#include<stdio.h>
#include<stdlib.h>

int main() {
    /*
        ADVANTAGE OF USING system() FUNCTION:
        YOU DO NOT NEED TO EXPLICITLY CALL fork() AND exec() FUNCTIONS.
        AUTOMATIC SIGNAL HANDLING IS DONE BY system() FUNCTION.
    */
    int status = system ("ls -l");
    if(status == -1) {
        perror("system");
        exit(EXIT_FAILURE);
    } else { // automatic wait() is done by system() function
        printf("Command exited with status %d\n", status);
    }
    return 0;
}

/**
 *  The system() function creates a new child process to execute the command. It does not execute the command in the existing process.
 */
