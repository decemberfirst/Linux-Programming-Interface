#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
    int fd = open("file.txt", O_RDONLY | O_APPEND); // append regardless of file offset
    return 0;
}
