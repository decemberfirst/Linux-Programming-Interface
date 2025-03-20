#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main() {
    pid_t pid = getpid();
    pid_t sid = getsid(pid);

    printf("Process ID: %d\n", pid);
    printf("Session ID: %d\n", sid);

    if(sid == pid) {
        printf("This process is a session leader\n");
    } else {
        printf("Leader is any other process\n");
    }
    return 0;
}
