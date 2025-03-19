/*
 * MUTEX ATTRIBUTES OPTIONS:
 * PTHREAD_MUTEX_NORMAL: Default mutex type.
 * PTHREAD_MUTEX_ERRORCHECK: Mutex type with error checking.
 * PTHREAD_MUTEX_RECURSIVE: Mutex type that allows the same thread to lock the mutex multiple times.
 */

 #define _GNU_SOURCE
#include <pthread.h>
#include <stdio.h>

pthread_mutex_t mutex;

void* threadFunc(void* arg) {
    pthread_mutex_lock(&mutex); // Lock count = 1
    printf("Locked once\n");

    pthread_mutex_lock(&mutex); // Lock count = 2
    printf("Locked twice\n");

    pthread_mutex_unlock(&mutex); // Lock count = 1
    printf("Unlocked once\n");

    pthread_mutex_unlock(&mutex); // Lock count = 0 (Mutex released)
    printf("Unlocked twice\n");

    return NULL;
}

int main() {
    pthread_t t1;
    pthread_mutexattr_t attr;

    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&mutex, &attr);

    pthread_create(&t1, NULL, threadFunc, NULL);
    pthread_join(t1, NULL);

    pthread_mutex_destroy(&mutex);
    return 0;
}
