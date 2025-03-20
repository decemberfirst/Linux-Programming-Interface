#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

/**
 * SYNTAX: int setpgid(pid_t pid, pid_t pgid);
 * if pid is 0, then the process ID of the calling process is changed, make leader
 * if pgid is specfied as 0, the calling process is specified as the leader of the new process group
 *
 * THESE ALL ARE EQUIVALENT:
 *
 setpgid(0, 0);
setpgid(getpid(), 0);
setpgid(getpid(), getpid());
 */

 /**
  * PID = TARGET PROCESS WHOSE PGID IS TO BE CHANGED
  * PGID = NEW PROCESS GROUP ID YOU WANT TO ASSIGN
  */

int main() {
    pid_t pid = getpid();
    pid_t pgid = getpgid(pid);

    printf("Before setting process group ID\n");
    printf("Process ID: %d\n", pid);
    printf("Process Group ID: %d\n", pgid);

    setpgid(pid, 0);
    printf("After setting process group ID\n");
    printf("Process ID: %d\n", pid);
    printf("Process Group ID: %d\n", getpgid(pid));
    return ;
}
