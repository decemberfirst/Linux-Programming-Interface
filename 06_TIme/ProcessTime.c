#include <stdio.h>
#include <time.h>

int main()
{
    clock_t start = clock();

    // Simulate work
    for (volatile long i = 0; i < 10; i++)
        ;

    clock_t end = clock();

    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Elapsed time: %.6f sec\n", elapsed_time);

    return 0;
}
