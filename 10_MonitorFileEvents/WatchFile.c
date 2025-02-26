#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/inotify.h>
#include <errno.h>

int main()
{
    int fd = inotify_init();
    if (fd == -1)
    {
        perror("inotify_init");
        exit(EXIT_FAILURE);
    }

    int wd = inotify_add_watch(fd, "file.txt", IN_MODIFY | IN_DELETE);
    if (wd == -1)
    {
        perror("inotify_add_watch");
        exit(EXIT_FAILURE);
    }

    char BUFFER[1024];
    while (1)
    {
        int length = read(fd, BUFFER, sizeof(BUFFER));

        // parse event data
        for (int i = 0; i < length;)
        {
            struct inotify_event *event = (struct inotify_event *)&BUFFER[i];
            // Print event details
            printf("Event on: %s\n", event->name);
            printf("Event file cookie: %d\n", event->cookie);
            if (event->mask & IN_MODIFY)
            {
                printf("File modified\n");
            }
            if (event->mask & IN_DELETE)
            {
                printf("File deleted\n");
            }

            // Move to the next event in the buffer
            i += sizeof(struct inotify_event) + event->len;
        }
    }
    return 0;
}

/**
 * struct format
 * struct inotify_event {
    int      wd;         // Watch descriptor (a unique identifier for the watch)
    uint32_t mask;       // Event mask: bit flags describing the event type (like IN_MODIFY, IN_CREATE)
    uint32_t cookie;     // A unique identifier for related events (optional)
    uint32_t len;        // Length of the name field (for event types like IN_MOVED_TO or IN_MOVED_FROM)
    char     name[];     // The name of the file (only available for certain events like IN_CREATE)
};

 */
