#include<stdio.h>
#include<limits.h>
#include<unistd.h>
#include<fcntl.h>

int main() {
    int fd = open("PathConf.c", O_RDONLY);
    printf("Maximum number of chars in file %ld \n",fpathconf(fd, _PC_NAME_MAX));
    printf("Maximum number of chars in path %ld \n",fpathconf(fd, _PC_PATH_MAX));
    return 0;
}
