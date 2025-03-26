#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <stdlib.h>

int main() {
    int tty_fd = open("/dev/tty", O_RDWR);
    if (tty_fd == -1) {
        perror("open");
        exit(1);
    }

    printf("Able to open /dev/tty for the first time\n");

    // detach the terminal
    if(ioctl(tty_fd, TIOCNOTTY) == -1) {
        perror("ioctl");
        exit(1);
    }

    printf("Detached the terminal\n");

    // try to open again
    tty_fd = open("/dev/tty", O_RDWR);
    if (tty_fd == -1) {
        perror("open after detach");
        exit(1);
    }

    printf("Able to open /dev/tty for the second time\n");

    return 0;
}
