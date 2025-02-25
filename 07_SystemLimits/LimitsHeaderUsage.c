#define _GNU_SOURCE
#include <stdio.h>
#include <limits.h>
// limits.h provides portable limits for all unix systems specified by SUSv3
// if want to use full power of dependent computer use earlier fns
// _POSIX PREFIX MEANS PORTABLE LIMITS
/*
    If you write a program using only these minimum values, your code will run on all POSIX-compliant systems.
    However, this might limit performance because some systems may support higher limits.
    To make full use of a system's capabilities, it's better to check the actual limit on that system using <limits.h>, sysconf(), or pathconf().
*/
int main()
{
    printf("%d \n", _POSIX_PATH_MAX);
    return 0;
}

/**
 * _POSIX_XXX_MAX (like _POSIX_PATH_MAX) is the smallest maximum value that all systems must support.
 *  For example, _POSIX_PATH_MAX is 255, meaning all POSIX systems must allow file paths at least 255 characters long.
 */
