#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(char argc, char *argv[]) {
    execlp(argv[1], argv[1], ".",  NULL);
    perror("execlp");
    return 0;
}
