# FILE IO UNIVERSAL

All system calls that perform I/O return a non-negative number, which Unix refers to as a file descriptor (FD for short). By convention, Unix opens three file descriptors—0, 1, and 2—for standard input (stdin), standard output (stdout), and standard error (stderr) respectively, when a process is created. We can use the constants `STDIN_FILENO`, `STDOUT_FILENO`, and `STDERR_FILENO` to refer to 0, 1, and 2, which makes the code more readable.
