#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char BUFFER[1024];
    int numberOfBytes = read(STDIN_FILENO, BUFFER, 1024);
    BUFFER[1023] = '\0';

    if (numberOfBytes == -1)
    {
        printf("Reading exited");
        exit(0);
    }

    write(STDOUT_FILENO, BUFFER, numberOfBytes);
    return 0;
}
