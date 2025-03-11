#include<stdio.h>
#include<limits.h>
#include<unistd.h>

int main() {
    printf("Maximum number of chars in file %ld \n",pathconf("/", _PC_NAME_MAX));
    printf("Maximum number of chars in path %ld \n",pathconf("/", _PC_PATH_MAX));
    return 0;
}
