#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main() {
    pid_t pid = getpid();
    pid_t pgid = getpgid(pid);

    printf("Process ID: %d\n", pid);
    printf("Process Group ID: %d\n", pgid);

    if(pgid == pid) {
        printf("This process is a process group leader\n");
    } else {
        printf("Leader is any other process\n");
    }

    return 0;
}
