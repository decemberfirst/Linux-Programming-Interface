#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

/*
    OPEN(const char *pathname, int flags, mode_t mode)
    ACCESS MODES: O_RDONLY, O_WRONLY, O_RDWR
*/

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <file>\n", argv[0]);
        return -1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return -1;
    }
    printf("File opened successfully ... \n");
    close(fd);
    return 0;
}
