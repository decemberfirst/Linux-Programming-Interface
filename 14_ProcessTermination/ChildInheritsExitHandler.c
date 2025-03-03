#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

// limitation of this exit is that we dont now the status code here
// another limitation is that we cannot pass argument to onexit function
void simpleExitHandler() {
    printf("The process has been terminated successfully ...\n");
}

int main() {
    atexit(simpleExitHandler);
    pid_t childFD = fork();
    if(childFD == 0) {
        sleep(3);
        printf("CHILD \n");
        exit(0);
    }

    wait(NULL);
    return 0;
}
