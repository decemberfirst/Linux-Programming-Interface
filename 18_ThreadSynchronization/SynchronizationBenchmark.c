#define _GNU_SOURCE
#include <stdio.h>
#include <pthread.h>
#include <sys/resource.h>

int balance = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *threadFN(void *arg) {
    struct rusage start_usage, end_usage;

    getrusage(RUSAGE_THREAD, &start_usage);

    for(int i = 0; i < 10000000; i++) {
        pthread_mutex_lock(&mutex);
        balance++;
        pthread_mutex_unlock(&mutex);
    }

    getrusage(RUSAGE_THREAD, &end_usage);

    long user_time_ms =
        (end_usage.ru_utime.tv_sec - start_usage.ru_utime.tv_sec) * 1000 +
        (end_usage.ru_utime.tv_usec - start_usage.ru_utime.tv_usec) / 1000;

    long system_time_ms =
        (end_usage.ru_stime.tv_sec - start_usage.ru_stime.tv_sec) * 1000 +
        (end_usage.ru_stime.tv_usec - start_usage.ru_stime.tv_usec) / 1000;

    printf("User CPU time in ms : %ld\n", user_time_ms);
    printf("System CPU time in ms : %ld\n", system_time_ms);

    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    int status1, status2;
    status1 = pthread_create(&thread1, NULL, threadFN, NULL);
    status2 = pthread_create(&thread2, NULL, threadFN, NULL);

    if(status1 != 0 || status2 != 0) {
        printf("Thread creation failed\n");
        return 1;
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final balance: %d\n", balance);
    return 0;
}
