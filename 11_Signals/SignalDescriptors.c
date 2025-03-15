#define _GNU_SOURCE
#include<stdio.h>
#include<signal.h>

extern const char *const sys_siglist[];

/**
 * STRSIGNAL PEFORMS BOUND CHECKING, IF SIGNAL IS OUT OF BOUND THEN IT RETURNS NULL
 * SIGNAL DESCRIPTION WILL BE RETURNED IN LOCAL LANGUAGE OF THE SYSTEM
 */

 void signalHandler(int signal) {
    printf("Signal Number: %d\n", signal);
   char *signalDescription = strsignal(signal);
    if(signalDescription == NULL) {
         printf("Signal Description: Signal out of bound\n");
    } else {
         printf("Signal Description: %s\n", signalDescription);
    }
 }

 int main() {
    signal(SIGINT, signalHandler);
    signal(SIGTERM, signalHandler);
    while(1) {

    }
    return 0;
 }
