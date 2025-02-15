#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h>

/*
    O_RDONLY OR O_WRONLY OR O_RDWR THROWS ERR IF FILE DOESN'T EXIST
*/

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage %s <filename> \n", argv[0]);
        exit(1);
    }

    int fd = open(argv[1], O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1)
    {
        printf("%d \n", errno);
        perror("Open");
        exit(1);
    }

    printf("File Opened Successfully ...");
    return 0;
}
