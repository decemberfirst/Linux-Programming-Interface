#define _GNU_SOURCE
#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd = open("file.txt", O_RDWR | O_DIRECT); // THIS NEEDS PROPER MEM-ALIGN
    if (fd == -1)
    {
        perror("Open");
        exit(1);
    }
    return 0;
}
