#include<stdio.h>
#include<pthread.h>

int balance = 0;
pthread_mutex_t mutex;
void *deposit(void *arg) {
    pthread_mutex_lock(&mutex);
    for(int i = 0; i < 1000000; i++) {
        balance++;
    }
    pthread_mutex_unlock(&mutex);
}

int main() {
    pthread_t first, second;
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&first, NULL, deposit, NULL);
    pthread_create(&second, NULL, deposit, NULL);

    pthread_join(first, NULL);
    pthread_join(second, NULL);

    pthread_mutex_destroy(&mutex);
    printf("The final balance is %d\n", balance);
    return 0;
}
