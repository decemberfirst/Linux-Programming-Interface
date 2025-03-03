// exit handler wont be run when exiting process with _exit()
// they dont execute if process is killed by SIGKILL and SIGSEGV

#include<stdio.h>
#include<stdlib.h>

void exitHandlerFunction() {
    printf("The process has been terminated successfully ...\n");
}

void registeredLastFn() {
    printf("This function will be executed first even registered last ...\n");
}

int main() {
    atexit(exitHandlerFunction); // register exit handler
    atexit(registeredLastFn); // this will run first even registered last
    exit(0);
}
