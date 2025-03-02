#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/wait.h>

int main() {
    char tempFileFormat[] = "testXXXXXX";
    int tempFd = mkstemp(tempFileFormat);
    if(tempFd == -1) {
        perror("mkstemp");
        exit(errno);
    }

    printf("File offset before fork: %lld \n", (long long) lseek(tempFd, 0, SEEK_CUR));
    int flags = fcntl(tempFd, F_GETFL);
    if(flags == -1) {
        perror("fcntl");
        exit(errno);
    }

    printf("O_APPEND flag before fork is %s\n", (flags & O_APPEND) ? "ON" : "OFF");

    switch(fork()) {
        case -1:
            perror("fork");
            exit(errno);
        case 0:
            lseek(tempFd, 1000, SEEK_SET);
            flags |= O_APPEND;
            fcntl(tempFd, F_SETFL, flags);
            break;
        default:
            wait(NULL);
            printf("Child has exited \n");
            printf("File offset in parent: %lld\n", (long long) lseek(tempFd, 0, SEEK_CUR));
            flags = fcntl(tempFd, F_GETFL);
            printf("O_APPEND flag for parent i: %s\n", (flags & O_APPEND) ? "ON" : "OFF");
    }
    return 0;
}
