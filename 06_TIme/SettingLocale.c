#include <stdio.h>
#include <locale.h>
#include <time.h>

int main()
{
    char BUFFER[100];
    char *setLocale = setlocale(LC_ALL, "ne_NP");
    printf("The locale is set to: %s\n", setLocale);

    time_t currentEpoch = time(NULL);
    struct tm *brokenTime = localtime(&currentEpoch);

    // use this fn for localized time
    strftime(BUFFER, sizeof(BUFFER), "%Y-%m-%d %H:%M:%S", brokenTime);
    printf("The Localized time is: %s\n", BUFFER);

    return 0;
}
