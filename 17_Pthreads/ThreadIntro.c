#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>

void *threadFunction(void *arg) {
    char *s = (char *)arg;
    printf("%s\n", s);
    return (void *) strlen(s);
}

int main(int argc, char *argv[]) {
    pthread_t threadID;
    void *threadResult;
    int status;

    status = pthread_create(&threadID, NULL, threadFunction, "Hello World\n");
    if(status !=0 ) {
        perror("pthread_create failed");
        exit(EXIT_FAILURE);
    }

    printf("Message from main()\n");
    pthread_join(threadID, &threadResult);
    printf("Thread returned %ld\n", (long)threadResult);
    return 0;
}
