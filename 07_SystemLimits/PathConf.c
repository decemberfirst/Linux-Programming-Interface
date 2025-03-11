#include<stdio.h>
#include<limits.h>
#include<unistd.h>

int main() {
    printf("Maximum number of chars in file %ld \n",pathconf("/", _PC_NAME_MAX));
    printf("Maximum number of chars in path %ld \n",pathconf("/", _PC_PATH_MAX));
    // If you write up to this size, the write will be atomic — meaning the entire write operation will either succeed completely or fail completely (no partial writes).
    printf("Maximum pipe buffer size %ld \n",pathconf("/", _PC_PIPE_BUF)); //
    return 0;
}
