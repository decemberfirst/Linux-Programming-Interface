#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <errno.h>

int main()
{
    struct timeval tv;
    struct tm new_time;

    new_time.tm_year = 2025 - 1900; // Year (since 1900)
    new_time.tm_mon = 1;            // Month (0 = Jan, 1 = Feb, ...)
    new_time.tm_mday = 20;          // Day of the month
    new_time.tm_hour = 12;          // Hour (24-hour format)
    new_time.tm_min = 30;           // Minutes
    new_time.tm_sec = 0;            // Seconds
    new_time.tm_isdst = -1;         // Auto-detect daylight saving time

    // Convert to epoch time (seconds since 1970)
    tv.tv_sec = mktime(&new_time);
    tv.tv_usec = 0; // Microseconds

    if (settimeofday(&tv, NULL) < 0)
    {
        perror("settimeofday failed");
        return 1;
    }

    printf("System time updated successfully!\n");
    return 0;
}
