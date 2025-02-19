#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/resource.h>

/*
-------------- BENCHMARK RESULTS ---------
    User Time: 73.977 ms
    System Time: 157.951 ms THIS SHOWS THAT AS YOU INCREASE BUFFER SIZE AFTER CERTAIN TIME RESULTS IS LITTLE IN CHANGE
*/

int main()
{
    char BUFFER[5000];
    int fd = open("benchmark.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1)
    {
        printf("Error opening file ...");
        return 1;
    }

    for (int i = 0; i < 10000000 / 300; i++)
    {
        for (int j = 0; j < 5000; j++)
        {
            BUFFER[j] = 'A';
        }
        write(fd, BUFFER, 100);
    }

    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);

    float userTime = (float)(usage.ru_utime.tv_sec) * 1000 + (float)(usage.ru_utime.tv_usec) / 1000;
    float systemTime = (float)(usage.ru_stime.tv_sec) * 1000 + (float)(usage.ru_stime.tv_usec) / 1000;

    printf("User Time: %.3f ms\n", userTime);
    printf("System Time: %.3f ms\n", systemTime);
    return 0;
}
