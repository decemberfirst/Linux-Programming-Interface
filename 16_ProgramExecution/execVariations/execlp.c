#include<stdio.h>
#include<unistd.h>

int main() {
    // l means you can pass arguments as a list
    // p means pathname is searched in PATH environment variable
    execlp("ls", "ROHAN", "-l", NULL);
    return 0;
}
