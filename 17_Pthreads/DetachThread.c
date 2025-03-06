/**
 * THREAD DETACH MEANS WE DONOT NEED EXPLICITLY JOIN THREAD
 * THREAD STATUS WILL BE AUTOMATICALLY RECLAIMED BY SYSTEM
 */

 #include<stdio.h>
 #include<pthread.h>

 void *thread_function(void *arg)
 {
    printf("Hello from thread\n");
    pthread_detach(pthread_self()); // pthread self returns itself thread id
    return NULL;
 }

    int main()
    {
        pthread_t thread;
        pthread_create(&thread, NULL, thread_function, NULL);
        pthread_join(thread, NULL); // this will not work as thread is detached
        return 0;
    }
