#include<stdio.h>
#include<limits.h>
#include<unistd.h>

// if used with sysconf
// returns -1 if the limit is not supported
// returns 0 if the limit maybe supported, check at runtime
// returns >0 if the limit is supported

int main() {
    // ---------CHECK POSIX THREADS ARE SUPPORTED OR NOT---------
    #ifdef _POSIX_THREADS
        printf("POSIX threads are supported\n");
    #else
        printf("POSIX threads are not supported\n");
    #endif

    // ---------CHECK ASYNCHRONOUS IO IS SUPPORTED OR NOT---------
    #ifdef _POSIX_ASYNCHRONOUS_IO
        printf("Asynchronous IO is supported\n");
    #else
        printf("Asynchronous IO is not supported\n");
    #endif

    // ---------CHECK MESSAGE PASSING IS SUPPORTED OR NOT---------
    #ifdef _POSIX_MESSAGE_PASSING
        printf("Message passing is supported\n");
    #else
        printf("Message passing is not supported\n");
    #endif

    // ---------CHECK SEMAPHORES ARE SUPPORTED OR NOT---------
    #ifdef _POSIX_SEMAPHORES
        printf("Semaphores are supported\n");
    #else
        printf("Semaphores are not supported\n");
    #endif
    return 0;
}
