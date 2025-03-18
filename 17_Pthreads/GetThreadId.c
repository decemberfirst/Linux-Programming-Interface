#include<stdio.h>
#include<pthread.h>

void *threadFunc(void *arg) {
    printf("Thread ID: %ld\n", pthread_self());
    return NULL;
}

int main() {
    pthread_t threadId;
    printf("Main Thread ID: %ld\n", pthread_self());
    pthread_create(&threadId, NULL, threadFunc, NULL);
    pthread_join(threadId, NULL);
    return 0;
}
