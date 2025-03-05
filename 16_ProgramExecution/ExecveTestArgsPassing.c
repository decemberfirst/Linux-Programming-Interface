#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2 || strcmp(argv[1], "--help") == 0) {
        fprintf(stderr, "%s pathname\n", argv[0]);
        exit(EXIT_FAILURE);
    }


    char *argVec[] = {strrchr(argv[1], '/') ? strrchr(argv[1], '/') + 1 : argv[1], "hello world", "goodbye", NULL};
    char *envVec[] = { "NAME=rohan", "FROM=nepal", NULL };

    execve(argv[1], argVec, envVec);
    perror("execve");
    exit(EXIT_FAILURE);
}
