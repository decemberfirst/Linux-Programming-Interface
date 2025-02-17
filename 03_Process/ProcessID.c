#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    printf("Current process id is: %d\n", getpid());
    printf("Parent process id is: %d\n", getppid());
    return 0;
}
