#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char BUFFER[100];
    int fd = open("file.txt", O_RDWR);
    if (fd == -1)
    {
        printf("Open");
        exit(1);
    }

    lseek(fd, 2, SEEK_SET);
    read(fd, BUFFER, 100);
    printf("Content read first time: \n");
    printf("%s", BUFFER);

    printf("Read again: \n");
    memset(BUFFER, 0, 100);
    lseek(fd, 0, SEEK_SET);

    read(fd, BUFFER, 100);
    printf("%s", BUFFER);

    return 0;
}
