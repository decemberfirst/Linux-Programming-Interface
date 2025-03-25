#include<stdio.h>
#include<sys/resource.h>

int main() {
    struct rlimit limit;
    getrlimit(RLIMIT_NOFILE, &limit);
    printf("Soft limit: %ld\n", limit.rlim_cur);
    printf("Hard limit: %ld\n", limit.rlim_max);
    return 0;
}
