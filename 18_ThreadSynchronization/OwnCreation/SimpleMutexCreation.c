#include<stdio.h>
#include<pthread.h>

// THIS PROGRAM DOESNOT WORK THOUGH
// WE NEED SUCH MECHANISM WHERE TESTING AND SETTING OF LOCK SHOULD BE ATOMIC ( ONE OPERATION)
int balance = 0;

struct lock {
    int lock;
} mutex;

void lock_init(struct lock *mutex) {
    mutex->lock = 0;
}

void lock_acquire(struct lock *mutex) {
    while(mutex->lock == 1); // when thread come to already locked case
    mutex->lock = 1; // Lock is acquired here
}

void lock_release(struct lock *mutex) {
    mutex->lock = 0; // Lock is released here
}

void *threadFunc(void *arg) {
    for(int i=0; i<20000; i++) {
        lock_acquire(&mutex);
        balance++;
        lock_release(&mutex);
    }
}

int main() {
    lock_init(&mutex);
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, threadFunc, NULL);
    pthread_create(&thread2, NULL, threadFunc, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final balance: %d\n", balance);
    printf("Expected balance: %d\n", 40000);
    return 0;
}
