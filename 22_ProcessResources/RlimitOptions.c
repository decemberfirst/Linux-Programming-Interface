#include<stdio.h>
#include<sys/resource.h>

int main() {
    struct rlimit rlim;

    // --------RLIMIT_AS (ADDRESS SPACE)------
    // SETS MAXIMUM SIZE OF PROCESSES VIRTUAL ADDRESS SPACE IN BYTES
    // getrlimit(RLIMIT_AS, &rlim);

    // --------RLIMIT_CORE (CORE FILE SIZE)------
    // SETS MAXIMUM SIZE OF CORE DUMP FILE THAT CAN BE GENERATED
    // getrlimit(RLIMIT_CORE, &rlim);

    // --------RLIMIT_CPU (CPU TIME)------
    // SETS MAXIMUM AMOUNT OF CPU TIME IN BOTH USER AND KERNEL MODE USED BY PROECESS
    // getrlimit(RLIMIT_CPU, &rlim);

    // --------RLIMIT_DATA (DATA SEGMENT)------ (INCLUDES: HEAP, DATA, BSS)
    // SETS MAXIMUM SIZE OF DATA SEGMENT IN BYTES
    // getrlimit(RLIMIT_DATA, &rlim);

    // --------RLIMIT_FSIZE (FILE SIZE)------
    // SETS MAXIMUM SIZE OF FILE THAT CAN BE CREATED BY PROCESS
    // getrlimit(RLIMIT_FSIZE, &rlim);

    // --------RLIMIT_MEMLOCK (LOCKED MEMORY)------
    // SETS MAXIMUM AMOUNT OF MEMORY THAT CAN BE LOCKED INTO RAM, MEANS DONOT SWAP TO DISK EVEN IN PRESSURE
    // getrlimit(RLIMIT_MEMLOCK, &rlim);

    // --------RLIMIT_NICE (NICE VALUE)------
    // SETS MAXIMUM NICE VALUE THAT CAN BE SET BY PROCESS
    // getrlimit(RLIMIT_NICE, &rlim);

    // --------RLIMIT_NOFILE (OPEN FILE DESCRIPTORS)------
    // SETS MAXIMUM NUMBER OF FILE DESCRIPTORS THAT CAN BE OPENED BY PROCESS
    // getrlimit(RLIMIT_NOFILE, &rlim);

    // --------RLIMIT_NPROC (NUMBER OF PROCESSES)------
    // SETS MAXIMUM NUMBER OF PROCESSES THAT CAN BE CREATED BY USER
    // getrlimit(RLIMIT_NPROC, &rlim);

    // --------RLIMIT_RSS (RESIDENT SET SIZE)------ (NO OF PHYSICAL PAGES ALLOCATED TO PROCESS)
    // SETS MAXIMUM SIZE OF RESIDENT SET SIZE IN BYTES
    // getrlimit(RLIMIT_RSS, &rlim);

    // --------RLIMIT_STACK (STACK SEGMENT)------
    // SETS MAXIMUM SIZE OF STACK SEGMENT IN BYTES
    // getrlimit(RLIMIT_STACK, &rlim);

    printf("Soft limit: %lu\n", rlim.rlim_cur);
    printf("Hard limit: %lu\n", rlim.rlim_max);
    return 0;
}
