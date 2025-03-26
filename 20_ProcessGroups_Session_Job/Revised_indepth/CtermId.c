#define _GNU_SOURCE
#include<stdio.h>

int main() {
    char *tty_name = ctermid(NULL); // name of the controlling terminal
    if (tty_name == NULL) {
        perror("ctermid");
        return 1;
    }

    printf("The name of the controlling terminal is %s\n", tty_name);
    return 0;
}
