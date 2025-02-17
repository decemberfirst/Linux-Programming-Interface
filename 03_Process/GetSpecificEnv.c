#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *envValue = getenv("rohan");
    printf("We got env value as %s\n", envValue);
    return 0;
}
