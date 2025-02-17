#include <stdio.h>
#include <stdlib.h>

extern char **environ; // equivalent to char *environ[]

int main()
{
    for (; *environ != NULL; environ++)
    {
        puts(*environ);
    }
    return 0;
}
