#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main()
{
    int fd = open("file.txt", O_RDWR);
    if (fd == -1)
    {
        perror("Open");
        exit(1);
    }

    char *BUFFER = "Rohan Tiwari";
    lseek(fd, 30, SEEK_CUR);
    write(fd, BUFFER, strlen(BUFFER));
    return 0;
}
