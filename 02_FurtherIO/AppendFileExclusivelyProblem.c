#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void append_data_without_sync(char *messgae)
{
    int fd = open("file.txt", O_RDWR);
    if (fd == -1)
    {
        perror("Open");
        exit(1);
    }

    lseek(fd, 0, SEEK_END);

    sleep(5);
    write(fd, messgae, strlen(messgae)); // append is not really atomic here
    close(fd);
}

int main()
{
    append_data_without_sync("First Process \n");
    append_data_without_sync("Second Process \n");
    return 0;
}
