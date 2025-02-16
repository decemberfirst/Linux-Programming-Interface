#define _GNU_SOURCE
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int fd = open("file.txt", O_RDWR);
    if (fd == -1)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char BUFFER[1024];
    read(fd, BUFFER, 1024);
    printf("%s\n", BUFFER);
    memset(BUFFER, 0, 1024);
    lseek(fd, 59, SEEK_SET);
    read(fd, BUFFER, 1024);
    printf("%s\n", BUFFER);
    close(fd);
    return 0;
}
