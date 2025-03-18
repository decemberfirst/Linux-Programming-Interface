#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *threadFirst(void *arg) {
   printf("First thread is running ...\n");
   sleep(5);
    printf("First thread is exiting ...\n");
    return NULL;
}

void *threadSecond(void *arg) {
    pthread_t *toWaitID = (pthread_t *)arg;
    pthread_join(*toWaitID, NULL);
    printf("Second thread is running ...\n");
    return NULL;
}

int main() {
    pthread_t first, second;
    pthread_create(&first, NULL, threadFirst, NULL);
    pthread_create(&second, NULL, threadSecond, &first);

    pthread_join(second, NULL);

    return 0;
}
