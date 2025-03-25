#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s limit_indicator\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct rlimit rlim;
    rlim.rlim_cur = (argv[1][0] == 'i') ? RLIM_INFINITY : atoi(argv[1]);
    rlim.rlim_max = (argv[1][0] == 'i') ? RLIM_INFINITY : atoi(argv[1]);

    if (setrlimit(RLIMIT_NPROC, &rlim) == -1) {
        perror("setrlimit");
        exit(EXIT_FAILURE);
    }

    printf("Soft limit: %lld\n", (long long) rlim.rlim_cur);
    printf("Hard limit: %lld\n", (long long) rlim.rlim_max);

    for (int i = 0; ; i++) {
        pid_t childPid = fork();
        if (childPid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (childPid == 0) {
            _exit(EXIT_SUCCESS);
        } else {
            printf("Child %d (PID=%ld) created\n", i, (long)childPid);

        }
    }

    return 0;
}
