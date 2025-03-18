/**
 *  THREAD ATTRIBUTES CAN INCLUDE THE FOLLOWING:
 * - Detach state: PTHREAD_CREATE_DETACHED or PTHREAD_CREATE_JOINABLE
 * - Scheduling policy: SCHED_FIFO, SCHED_RR, or SCHED_OTHER
 * - STACK SIZE
 * - STACK ADDRESS
 * AND MORE
 */
#include<stdio.h>
#include<pthread.h>

void *myThreadFunc(void *arg) {
    printf("Thread ID: %ld\n", pthread_self());
    return NULL;
}

int main() {
    pthread_t threadId;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED); // MAKE THIS THREAD NOT JOINABLE
    pthread_create(&threadId, &attr, myThreadFunc, NULL);
    pthread_join(threadId, NULL); // THIS DOESNOT WORK DUE TO DETCHED STATE
    return 0;
}
