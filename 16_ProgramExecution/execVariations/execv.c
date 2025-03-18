#include<stdio.h>
#include<unistd.h>

int main() {
    char *args[] = {"ls", "-l", NULL};
    execv("/bin/ls", args); // using just ls doesnot work here
    return 0;
}
