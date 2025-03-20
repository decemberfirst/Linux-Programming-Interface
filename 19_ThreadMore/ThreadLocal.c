/**
 * REENTRANT FUNCTION IS SUCH A FUNCTION THAT CAN BE CALLED BY MULTIPLE THREADS AT THE SAME TIME WITHOUT WORRYING ABOUT THE MULTIPLE THREADS INTERFERING WITH EACH OTHER.
 */

#define _GNU_SOURCE
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_key_t key;
pthread_once_t key_once = PTHREAD_ONCE_INIT;

void data_destructor(void *data) {
    printf("Data destructor called in thread %ld\n", pthread_self());
    free(data);
}

void create_key() {
    pthread_key_create(&key, data_destructor);
}

void *thread_function(void *arg) {
    // create key once for all the threads
    pthread_once(&key_once, create_key);

    int *data = (int*) pthread_getspecific(key); // returns the mapping data for the current thread
    if(data == NULL) {
        data = (int *) malloc(sizeof(int)); // allocate memory for the data
        if(data == NULL) {
            perror("malloc");
            exit(1);
        }

        *data = (int) (long) arg;
        // set the data for the current thread
        pthread_setspecific(key, data); // set the mapping data for the current thread
        printf("Thread %ld: First call, data = %d\n", pthread_self(), *data);
    } else {
        printf("Thread %ld existing data = %d\n", pthread_self(), *data);
    }

    sleep(1);
    (*data)++;
    printf("Thread %ld: Updated data = %d\n", pthread_self(), *data);

    return NULL;
}

int main() {
    pthread_t threads[3];

    for(int i=0; i<3; i++) {
        pthread_create(&threads[i], NULL, thread_function, (void*) (long)(i+1));
    }

    for(int i=0; i<3; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
