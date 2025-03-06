#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
    int flags;
    if(argc > 1) {
        flags = fcntl(STDOUT_FILENO, F_GETFD);
        if(flags == -1) {
            perror("fcntl");
            exit(EXIT_FAILURE);
        }

        flags |= FD_CLOEXEC; // set the FD_CLOEXEC flag

        if(fcntl(STDOUT_FILENO, F_SETFD, flags) == -1) { // update flags
            perror("fcntl");
            exit(EXIT_FAILURE);
        }
    }

    execlp("ls", "ls", "-l", argv[0], NULL);
    exit(EXIT_FAILURE);
}
