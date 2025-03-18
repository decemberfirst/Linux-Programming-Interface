#include<stdio.h>
#include<unistd.h>

int main() {
    execl("/bin/echo", "ROHAN", "ROHAN TIWARI", NULL);
    return 0;
}
