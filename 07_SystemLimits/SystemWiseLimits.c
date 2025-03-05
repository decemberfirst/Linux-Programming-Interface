#define _GNU_SOURCE
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

int main()
{
    long open_max = sysconf(_SC_OPEN_MAX);
    long max_args = sysconf(_SC_ARG_MAX);
    printf("Max number of open files is %ld\n", open_max);         // got 1048576
    printf("Maximum number of args i can pass: %ld \n", max_args); // got 2097152


    printf("Maximum number of bytes in a pathname including terminating null byte: %d\n", PATH_MAX); // got 4096
    printf("Maximum number of bytes in filename: %d\n", NAME_MAX);                                   // got 255
    return 0;
}
