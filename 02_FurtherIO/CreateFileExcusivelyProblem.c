#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
/*USE TWO PROCESSES TO REALLY SEE THE PROBLEM*/
/*BOTH PROCESSES CLAIM THEMSELVES CREATING THE FILE*/

int main(int argv, char *argc[])
{

    int fd = open("file.txt", O_RDWR);
    if (fd != -1)
    {
        printf("File Already Exists ...");
        exit(0);
    }
    else
    {
        if (argv > 2)
        {
            sleep(5);
        }
        int fds = open("file.txt", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
        if (fds == -1)
        {
            perror("Open");
            exit(1);
        }

        printf("File Created  Successfully ...\n");
        printf("PID [%d] created the file : ", getpid());
    }
    return 0;
}
