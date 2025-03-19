#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int producedValue = -1;

void *producer(void *arg) {
    while(1) {
        pthread_mutex_lock(&mutex);
        producedValue = rand() % 100;
        printf("Produced: %d\n", producedValue);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

void *consumer(void *arg) {
    while(1) {
        pthread_mutex_lock(&mutex);
        while(producedValue == -1) {
            pthread_cond_wait(&cond, &mutex);
        }
        printf("Consumed: %d\n", producedValue);
        producedValue = -1;
        sleep(3);
        pthread_mutex_unlock(&mutex);
    }
}

int main() {
    srand(time(NULL));
    pthread_t prod, con;
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&con, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(con, NULL);
    return 0;
}
