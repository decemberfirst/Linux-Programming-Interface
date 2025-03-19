#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 3
#define PRODUCER_THREADS 5
#define CONSUMER_THREADS 2

sem_t empty, full;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int in = 0, out = 0;
int BUFFER[BUFFER_SIZE];

void *producer(void *arg) {
    pthread_t threadId = pthread_self();
    printf("Producer thread id: %ld has started\n", threadId);

    while(1) {
        sem_wait(&empty);

        pthread_mutex_lock(&mutex); // we need mutex because we are accessing shared variable BUFFER
        BUFFER[in] = rand() % 100;
        printf("Produced: %d\n", BUFFER[in]);
        in = (in + 1) % BUFFER_SIZE;
        pthread_mutex_unlock(&mutex);

        sem_post(&full);
        sleep(1);
    }
}

void *consumer(void *arg) {
    pthread_t threadId = pthread_self();
    printf("Consumer thread id: %ld has started\n", threadId);

    while(1) {
        sem_wait(&full);

        pthread_mutex_lock(&mutex);
        int consumedValue = BUFFER[out];
        printf("Consumed: %d\n", consumedValue);
        out = (out + 1) % BUFFER_SIZE;
        pthread_mutex_unlock(&mutex);

        sem_post(&empty);
        sleep(2);
    }
}

int main() {
    pthread_t producers[PRODUCER_THREADS], consumers[CONSUMER_THREADS];

    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);

    for (int i = 0; i < PRODUCER_THREADS; i++) {
        pthread_create(&producers[i], NULL, producer, NULL);
    }

    for (int i = 0; i < CONSUMER_THREADS; i++) {
        pthread_create(&consumers[i], NULL, consumer, NULL);
    }

    for (int i = 0; i < PRODUCER_THREADS; i++) {
        pthread_join(producers[i], NULL);
    }

    for (int i = 0; i < CONSUMER_THREADS; i++) {
        pthread_join(consumers[i], NULL);
    }

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}
