# FILE IO UNIVERSAL

All system calls that perform I/O return a non-negative number, which Unix refers to as a file descriptor (FD for short). By convention, Unix opens three file descriptors—0, 1, and 2—for standard input (stdin), standard output (stdout), and standard error (stderr) respectively when a process is created. We can use the constants `STDIN_FILENO`, `STDOUT_FILENO`, and `STDERR_FILENO` to refer to 0, 1, and 2, which makes the code more readable.

# UNIVERSAL IO SYSTEM CALLS

There are three primary system calls that work with different types of files (such as sockets, regular disk files, pipes, etc.): `open`, `read`, and `write`.

## open

The `open` system call is used to open a file. On success, it returns the lowest available non-negative file descriptor (FD). If opening the file fails for various reasons (such as permission denied, file does not exist, etc.), it returns -1. Here is the syntax for the `open` system call:

```c
int open(const char *pathname, int flags, mode_t mode);
```

### ACCESS MODES

- `O_RDONLY` -> Open the file for read only
- `O_RDWR` -> Open the file for read and write both
- `O_WRONLY` -> Open the file for write only
- `O_CLOEXEC`-> Set the close on exec flag
- `O_CREAT` -> Create the file if not exists
- `O_DIRECT` -> Bypass the buffer cache
- `O_DIRECTORY` -> Throw error if pathname is not directory
- `O_EXCL` -> Create file exclusively , Often used with O_CREAT
- `O_NOATIME`-> Donot update last access time on read sytem call
- `O_NOFOLLOW` -> Donot dereference symbolic links
- `O_TRUNC` -> Truncate existing file to zero length
- `O_APPEND` -> Writes are always appended to a file
- `O_ASYNC` -> Generates a signal when I/O possible
- `O_SYNC` -> Make file write synchronous
- `O_NONBLOCK` -> Open in non blocking mode

# read system call

`read` system call takes three parameters. file descriptor (FD), pointer to buffer and number of bytes we want to read respectively. if read succeed, number of bytes that have been read is returned .

# write system call

`write` sytem call takes three parameters. file descriptor (FD), pointer to buffer that you want to flush to disk, at last number of bytes you want to write. if write succeed it returns number of bytes written to the disk. write system call doesnot gurantee that content you write may not be immediately flushed to disk due to batch write.
