#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>

int main() {
    struct rlimit rlimit;

    if (getrlimit(RLIMIT_NICE, &rlimit) == 0) {
        printf("Soft limit: %ld\n", rlimit.rlim_cur); // 0 MEANS NO LIMIT
        printf("Hard limit: %ld\n", rlimit.rlim_max);
    } else {
        perror("getrlimit failed");
    }

    return 0;
}
