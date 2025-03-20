#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_once_t onceControl = PTHREAD_ONCE_INIT;

void initFn() {
    printf("Thread is running\n");
    sleep(5);
    printf("Thread exited\n");
}

int main() {
    pthread_t thread;
    pthread_once(&onceControl, initFn);
    pthread_once(&onceControl, initFn); // this will not run initFn again

    printf("Main thread exited\n");
    return 0;
}
