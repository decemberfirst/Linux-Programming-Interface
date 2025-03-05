#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(char argc, char *argv[]) {
    char *envVector[] = { "NAME=rohan", "FROM=nepal", NULL };
    execle(argv[1], argv[1], NULL, envVector);
    perror("execle");
    return 0;
}
