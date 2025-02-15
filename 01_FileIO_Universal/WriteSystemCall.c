#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage %s <filename>\n", argv[0]);
        exit(1);
    }

    int fd = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1)
    {
        perror("Open");
        exit(1);
    }

    char *contentToWrite = "Hello i am rohan tiwari";
    write(fd, contentToWrite, strlen(contentToWrite));
    return 0;
}
