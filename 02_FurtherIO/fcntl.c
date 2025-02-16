#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/*FCNTL IS USED TO MODIFY FILE DESCRIPTOR AT RUNTIME*/
int main()
{
    int fd = open("file.txt", O_RDWR);
    if (fd == -1)
    {
        perror("Open");
        exit(1);
    }

    int flags = fcntl(fd, F_GETFL);
    if (flags == -1)
    {
        perror("Flags");
        exit(1);
    }

    // update fd status flag like append, sync, non block and so on
    // cannot update access mode flags like rdrw and so on
    flags |= O_APPEND;
    fcntl(fd, F_SETFL, flags);

    if (write(fd, "Rohan", 5) == -1)
    {
        perror("Write");
        exit(1);
    }
    return 0;
}
