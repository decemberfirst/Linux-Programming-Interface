#define _GNU_SOURCE
#include<limits.h>
#include<sys/inotify.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#define BUF_LEN (10 * (sizeof(struct inotify_event) + NAME_MAX + 1)) // NAME_MAX BECAUSE NAME FIELD IN inotify_event is of variable length, 1 FOR NULL TERMINATOR

static void displayInotifyEvent(struct inotify_event *i) {
    printf("Watch Descriptor: %d\n", i->wd);
    if(i->cookie > 0) { // cookie is of type uint32_t
        printf("Cookie: %d\n", i->cookie);
    }

    printf("Mask: ");
    if(i->mask & IN_ACCESS) printf("IN_ACCESS "); // TRIGGERED WHEN READ(2) OR WRITE(2) SYSTEM CALLS ARE MADE
    if(i->mask & IN_ATTRIB) printf("IN_ATTRIB "); // TRIGGERED WHEN ATTRIBUTES LIKE PERMISSIONS, OWNER, TIMESTAMP ETC ARE CHANGED
    if(i->mask & IN_CLOSE) printf("IN_CLOSE "); // TRIGGERED WHEN FILE IS CLOSED
    if(i->mask & IN_CLOSE_NOWRITE) printf("IN_CLOSE_NOWRITE "); // TRIGGERED WHEN FILE IS CLOSED AFTER NOT BEING OPENED FOR WRITE
    if(i->mask & IN_CLOSE_WRITE) printf("IN_CLOSE_WRITE "); // TRIGGERED WHEN FILE IS CLOSED AFTER BEING OPENED FOR WRITE
    if(i->mask & IN_CREATE) printf("IN_CREATE "); // TRIGGERED WHEN FILE IS CREATED
    if(i->mask & IN_DELETE) printf("IN_DELETE "); // TRIGGERED WHEN FILE IS DELETED
    if(i->mask & IN_DELETE_SELF) printf("IN_DELETE_SELF "); // TRIGGERED WHEN SELF FILE IS DELETED
    if(i->mask & IN_IGNORED) printf("IN_IGNORED "); // TRIGGERED WHEN WATCH IS REMOVED
    if(i->mask & IN_ISDIR) printf("IN_ISDIR ");
    if(i->mask & IN_MODIFY) printf("IN_MODIFY "); // TRIGGERED WHEN FILE IS MODIFIED
    if(i->mask & IN_MOVE_SELF) printf("IN_MOVE_SELF "); // TRIGGERED WHEN SELF FILE IS MOVED
    if(i->mask & IN_MOVED_FROM) printf("IN_MOVED_FROM ");
    if(i->mask & IN_MOVED_TO) printf("IN_MOVED_TO ");
    if(i->mask & IN_OPEN) printf("IN_OPEN ");
    if(i->mask & IN_Q_OVERFLOW) printf("IN_Q_OVERFLOW ");
    if(i->mask & IN_UNMOUNT) printf("IN_UNMOUNT ");
    printf("\n");

    if(i->len > 0) {
        printf("Name: %s\n", i->name); // IT IS SET WHEN THE EVENT IS FOR A FILE INSIDE A DIRECTORY
    }

    printf("---READ COMPLETE---\n");
}


int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s <file1> <file2> ... <fileN>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char buffer[BUF_LEN];

    int fd = inotify_init();
    if(fd < 0) {
        perror("inotify_init");
        exit(EXIT_FAILURE);
    }

    // watch all the files passed from terminal arguments
    for(int i=1; i<argc; i++) {
        int watch_descriptor = inotify_add_watch(fd, argv[i], IN_ALL_EVENTS); //MASK-> watch all events
        if(watch_descriptor < 0) {
            perror("inotify_add_watch");
            exit(EXIT_FAILURE);
        }

        printf("Watching %s using watch descriptor %d\n", argv[i], watch_descriptor);
    }

    // wait for events to occur
    for(;;) {
        int num_bytes = read(fd, buffer, BUF_LEN);
        if(num_bytes < 0) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        printf("Read %d bytes from inotify fd\n", num_bytes);
        // process the events
        //  p<buffer+num_bytes because buffer+num_bytes is the address of the byte after the last byte of the buffer

        for(char *p = buffer; p<buffer+num_bytes;) {
            struct inotify_event *event = (struct iotify_event *)p;
            displayInotifyEvent(event);
            p = p + sizeof(struct inotify_event) + event->len; // event-> len is the length of the name field
        }
    }

    return 0;
}
