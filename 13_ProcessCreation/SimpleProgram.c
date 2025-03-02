#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include<errno.h>
#include<stdlib.h>
static int data = 10;
int main() {
    int stackData = 200;
    pid_t childPID;

    switch(childPID = fork()) {
        case -1:
            perror("Fork");
            exit(errno);
        case 0:
            printf("Hello i am child process \n");
            stackData += 20;
            data+= 20;
            break;
        default:
            printf("Hello i am parent process \n");
    }

    printf("PID=%ld %s idata=%d istack=%d\n", (long) getpid(),(childPID == 0) ? "(child) " : "(parent)", data, stackData);
    return 0;
}
