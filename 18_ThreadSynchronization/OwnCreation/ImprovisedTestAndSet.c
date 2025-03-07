#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

int balance = 0;

struct lock {
    int lock;
} mutex;

// WHAT THIS FN DOES IS TEST AND SET THE VALUE AND RETURN OLD VALUE OFTEN CALLED AS COMPARE AND SWAP TOO
static inline int xchg(int *ptr, int x) {
    __asm__ __volatile__("lock xchg %0, %1"
                         : "+m"(*ptr), "+r"(x)
                         :
                         : "memory");
    return x;
}

// THIS WILL BE THE SPIN LOCK THOUGH
// CPU CYCLE WILL BE WASTED HERE

void lock_init(struct lock *mutex) {
    mutex->lock = 0;
}

void lock_acquire(struct lock *mutex) {
    while(xchg(&mutex->lock, 1) == 1); // when thread come to already locked case, TESTING AND SETTING DONE HERE
}

void lock_release(struct lock *mutex) {
   xchg(&mutex->lock, 0); // Lock is released here
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
