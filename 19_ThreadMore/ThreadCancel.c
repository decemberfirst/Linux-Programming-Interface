#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *threadFunc(void *arg) {
    printf("threadFunc is running\n");
    sleep(5);
    printf("Thread func exited ...\n");
}

void *threadLongTask(void *arg) {
    printf("threadLongTask is running\n");
    while(1) {
        printf("threadLongTask is running\n");
        sleep(5);
    }
    printf("Thread long task exited ...\n");
}

int main() {
    pthread_t thread, thread2;
    pthread_create(&thread2, NULL, threadLongTask, NULL);
    pthread_create(&thread, NULL, threadFunc, NULL);
    sleep(2);
    pthread_cancel(thread);
    printf("waiting for thread to finish...\n");
    pthread_join(thread, NULL);
    pthread_join(thread2, NULL);
    return 0;
}
