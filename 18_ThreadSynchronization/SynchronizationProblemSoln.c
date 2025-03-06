#include<stdio.h>
#include<pthread.h>

int balance = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *threadFN(void *arg) {
    pthread_mutex_lock(&mutex);
    for(int i=0; i<20000; i++) {
        balance++;
    }
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    int status1, status2;
    status1 = pthread_create(&thread1, NULL, threadFN, NULL);
    status2 =  pthread_create(&thread2, NULL, threadFN, NULL);

    if(status1 != 0 || status2 != 0) {
        printf("Thread creation failed\n");
        return 1;
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final balance: %d\n", balance);
    return 0;
}
