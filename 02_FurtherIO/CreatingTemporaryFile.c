#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    char template[] = "rohanXXXXXX";
    int fd = mkstemp(template);

    if (fd == -1)
    {
        perror("mkstemp failed");
        return 1;
    }

    printf("Temporary file created: %s\n", template);

    close(fd);
    return 0;
}
