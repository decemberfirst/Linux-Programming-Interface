#include <stdio.h>
#include <stdlib.h>

int main()
{
    setenv("name", "rohan", 1); // 1 means override
    printf("I got env for name  %s", getenv("name"));
    return 0;
}
