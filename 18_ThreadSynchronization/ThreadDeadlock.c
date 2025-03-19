#include<stdio.h>
#include<pthread.h>

pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER, lock2 = PTHREAD_MUTEX_INITIALIZER;
int sharedResourceFirst = 0;
int sharedResourceSecond = 0;

void *thread1() {
    pthread_mutex_lock(&lock1);
    printf("Thread 1 acquired lock1\n");
    sleep(2);
    printf("Waiting for lock2\n");
    pthread_mutex_lock(&lock2);
    printf("Thread 1 acquired lock2\n");
    sharedResourceFirst++;
    sharedResourceSecond++;
    pthread_mutex_unlock(&lock2);
    pthread_mutex_unlock(&lock1);
    return NULL;
}

void *thread2() {
    pthread_mutex_lock(&lock2);
    printf("Thread 2 acquired lock2\n");
    sleep(2);
    printf("Waiting for lock1\n");
    pthread_mutex_lock(&lock1);
    printf("Thread 2 acquired lock1\n");
    sharedResourceFirst++;
    sharedResourceSecond++;
    pthread_mutex_unlock(&lock1);
    pthread_mutex_unlock(&lock2);
    return NULL;
}

int main() {
    pthread_t first, second;

    pthread_create(&first, NULL, thread1, NULL);
    pthread_create(&second, NULL, thread2, NULL);

    printf("Waiting for threads to complete\n");
    pthread_join(first, NULL);
    pthread_join(second, NULL);

    return 0;
}
