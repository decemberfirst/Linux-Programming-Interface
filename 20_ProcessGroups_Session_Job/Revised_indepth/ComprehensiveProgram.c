#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

void handle_sighup(int sig) {
    printf("[SESSION LEADER] Received SIGHUP, Terminal disconnected\n");
}

void monitor_child_process() {
    int status;
    pid_t pid;

    while ((pid = wait(&status)) > 0) {
        if (WIFEXITED(status)) {
            printf("[MONITOR] child process %d exited with status %d\n", pid, WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("[MONITOR] child process %d killed by signal %d\n", pid, WTERMSIG(status));
        }
    }
}

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        printf("[PARENT] Exiting to allow daemonization\n");
        _exit(EXIT_SUCCESS);
    }

    // Create new session for child
    if (setsid() == -1) {
        perror("setsid");
        exit(EXIT_FAILURE);
    }

    // Handle terminal disconnect
    struct sigaction sa;
    sa.sa_handler = handle_sighup;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGHUP, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("[SESSION LEADER] PID=%ld, PGID=%ld, SID=%ld\n",
           (long)getpid(), (long)getpgrp(), (long)getsid(0));

    // Open terminal as the controlling terminal (optional test)
    int tty_fd = open("/dev/tty", O_RDWR | O_NOCTTY);
    if (tty_fd == -1) {
        perror("open");
    } else {
        printf("[SESSION LEADER] Opened terminal\n");
    }

    // Fork multiple children to simulate multiple jobs
    for (int i = 0; i < 3; i++) {
        pid_t child_pid = fork();
        if (child_pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (child_pid == 0) {
            printf("[CHILD] PID=%ld, PGID=%ld, SID=%ld\n",
                   (long)getpid(), (long)getpgrp(), (long)getsid(0));
            sleep(5 + i);
            _exit(EXIT_SUCCESS);
        }
    }

    monitor_child_process();
    return 0;
}
