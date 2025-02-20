#include <stdio.h>
#include <sys/stat.h>

int main()
{
    struct stat statBuffer;
    stat("file.txt", &statBuffer);

    printf("Device On Which File Resides : %ld\n", statBuffer.st_dev);
    printf("Inode Number Of a file: %ld \n", statBuffer.st_ino);
    printf("File Mode And Permission: %d \n", statBuffer.st_mode);
    printf("Number of hard links: %ld \n", statBuffer.st_nlink);
    printf("User ID of file owner: %d \n", statBuffer.st_uid);
    printf("Group ID of file owner: %d \n", statBuffer.st_gid);
    printf("Total file size: %ld \n", statBuffer.st_size);
    printf("Total Block Size: %ld \n", statBuffer.st_blksize);
    printf("Number of blocks allocated: %ld \n", statBuffer.st_blocks);
    printf("Last accessed time: %ld \n", statBuffer.st_atime);
    printf("Last modified time: %ld \n", statBuffer.st_mtime);      // file content change time
    printf("Last status change time: %ld \n", statBuffer.st_ctime); // metadata, permission change time
    return 0;
}
