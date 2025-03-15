#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

void printSignalSet(const sigset_t *set) {
    int sig, count = 0;
    for(sig = 1; sig < NSIG; sig++) {
        if(sigismember(set, sig)) {
            count++;
            printf("%d (%s)\n", sig, strsignal(sig));
        }
    }

    if(count == 0) {
        printf("empty signal set\n");
    }
}

int printCurrentSigMask() {
    sigset_t currentMask;
    if(sigprocmask(SIG_BLOCK, NULL, &currentMask) == -1) {
        return -1;
    }

    printf("Blocked Signals:\n");
    printSignalSet(&currentMask);
    return 0;
}

int printPendingSignals() {

    sigset_t pendingSignals;
    if(sigpending(&pendingSignals) == -1) {
        return -1;
    }

    printf("Pending Signals:\n");
    printSignalSet(&pendingSignals);
    return 0;
}

int main() {

    return 0;
}
