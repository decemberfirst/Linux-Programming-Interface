#include <stdio.h>
#include <utime.h>
#include <unistd.h>
#include <time.h>

int main()
{
    struct utimbuf updated_times;
    updated_times.actime = time(NULL);  // Update access time to current time
    updated_times.modtime = time(NULL); // Update modified time to current time

    int result = utime("file.txt", &updated_times);
    if (result == -1)
    {
        perror("Error updating timestamps");
        return 1;
    }

    printf("Timestamps updated successfully.\n");
    return 0;
}
