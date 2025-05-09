#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>
#include <sys/time.h>
/*
    Elapsed Time: 11761.598 ms (calculcate cpu io wait time from here) (POOR PERFORMANCE DUE TO SYNC FILE INTEGRITY)
    User Time: 23.693 ms
    System Time: 370.359 ms
*/
int main()
{
    struct timeval start, end;
    gettimeofday(&start, NULL);

    char BUFFER[200];
    int fd = open("benchmark.txt", O_RDWR | O_CREAT | O_SYNC, S_IRUSR | S_IWUSR);
    if (fd == -1)
    {
        perror("Open");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < 5000; i++)
    {
        for (int j = 0; j < 200; j++)
        {
            BUFFER[j] = 'A';
        }

        write(fd, BUFFER, 100);
    }

    close(fd);

    gettimeofday(&end, NULL);

    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);

    float userTime = (float)(usage.ru_utime.tv_sec) * 1000 + (float)(usage.ru_utime.tv_usec) / 1000;
    float systemTime = (float)(usage.ru_stime.tv_sec) * 1000 + (float)(usage.ru_stime.tv_usec) / 1000;
    float elapsedTime = (end.tv_sec - start.tv_sec) * 1000.0;
    elapsedTime += (end.tv_usec - start.tv_usec) / 1000.0;

    printf("Elapsed Time: %.3f ms\n", elapsedTime);
    printf("User Time: %.3f ms\n", userTime);
    printf("System Time: %.3f ms\n", systemTime);

    return 0;
}
