#define _GNU_SOURCE
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int fd;
    size_t numRead;
    size_t length;
    off_t offset = 0;
    size_t alignment = 512;
    void *buf;

    if (argc < 3 || strcmp(argv[1], "--help") == 0) {
        printf("Usage: %s <file> <num-bytes>\n", argv[0]);
        exit(1);
    }

    length = atoi(argv[2]);

    if (argc > 3) {
        offset = atoi(argv[3]);
    }

    if (argc > 4) {
        alignment = atoi(argv[4]);
    }

    fd = open(argv[1], O_RDONLY | O_DIRECT);
    if (fd == -1) {
        perror("open");
        exit(1);
    }


    if (posix_memalign(&buf, alignment, length + alignment) != 0) {
        perror("posix_memalign");
        exit(1);
    }

    if (lseek(fd, offset, SEEK_SET) == -1) {
        perror("lseek");
        exit(1);
    }

    numRead = read(fd, buf, length);
    if (numRead == -1) {
        perror("read");
        exit(1);
    }

    printf("Read %ld bytes\n", (long) numRead);

    free(buf);
    close(fd);
    return 0;
}
