#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

/*
 THE PROGRAM SHOWS THE UNIVERSIALITY IO MECHANISM IN UNIX
 SINCE EVERYTHING IS FILE IN UNIX, WE CAN USE THE SAME SYSTEM CALLS TO READ AND WRITE FILES, SOCKETS, PIPES, ETC.
*/

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc < 3) {
        printf("Usage: %s <src> <dst>\n", argv[0]);
        return -1;
    }
    int readFd = open(argv[1], O_RDONLY);
    if(readFd == -1) {
        perror("open");
        return -1;
    }
    char BUFFER[BUF_SIZE];
    int readBytes = read(readFd, BUFFER, BUF_SIZE);
    if(readBytes == -1) {
        perror("read");
        return -1;
    }
    int writeFd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    int writeBytes = write(writeFd, BUFFER, readBytes);
    if(writeBytes == -1) {
        perror("write");
        return -1;
    }
    close(readFd);
    close(writeFd);
    return 0;
}
