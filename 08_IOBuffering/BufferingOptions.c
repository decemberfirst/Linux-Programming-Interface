#include <stdio.h>
#define BUFFER_SIZE 100
// stdout is line buffered
//  For output streams (like when writing data), the system stores data in a buffer and only writes it to the terminal or file when it encounters a newline character (like \n).

//  if the buffer gets full before a newline is encountered, the system will flush the buffer and output the data anyway.

// For input streams (like when reading data), the system reads data one line at a time. It waits for the newline character before considering the line complete.

int main()
{
    char buf[BUFFER_SIZE];
    setvbuf(stdout, buf, _IOFBF, BUFFER_SIZE);
    // MODE TAKES THREE OPTIONS
    // _IONBF -> NO BUFFERING, IMMEDIATE READ WRITE
    // _IOFBF -> FULL BUFFERING
    // _IOLBF -> LINE BUFFERING
    return 0;
}
