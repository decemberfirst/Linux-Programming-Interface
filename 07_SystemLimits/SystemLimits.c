#define _GNU_SOURCE
#include <stdio.h>
#include <sys/resource.h>
// runtime limits are determined by these three fns
// sysconf, pathconf, fpathconf
int main()
{
    struct rlimit rl;
    getrlimit(RLIMIT_NOFILE, &rl);
    printf("soft limit open files are : %ld \n", rl.rlim_cur);
    printf("Max files you can open is : %ld \n", rl.rlim_max);
    return 0;
}
