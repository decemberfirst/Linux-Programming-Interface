#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
    setenv("USER", "UPDATED_ONE", 1);
    execl(argv[1], "/bin/printenv", "USER", "SHELL", NULL);
    perror("execl");
    return 0;
}
