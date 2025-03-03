#define _DEFAULT_SOURCE
#include<stdio.h>
#include<stdlib.h>

void handleExit(int statusCode, void *arg) {
    printf("Exiting on_exit handler\n");
    printf("Got status code %d\n", statusCode);
    printf("Got argument: %d\n", *((int *)arg));
}

int main() {
    int number = 42;
    on_exit(handleExit, &number);

    printf("Exiting main\n");
    return 1;
}
