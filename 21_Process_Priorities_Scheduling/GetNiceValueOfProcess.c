#include<stdio.h>
#include<sys/resource.h>

/**
 * WHICH TAKES:
 * PRIO_PROCESS : OPERATE ON THE PROCESS WHOSE PROCESS ID EQUALS WHO, IF WHO IS 0 USE CALLER ID
 * PRIO_PGRP : OPERATE ON THE PROCESS GROUP WHOSE GROUP ID EQUALS WHO, IF WHO IS 0 USE CALLER ID
 * PRIO_USER : OPERATE ON THE PROCESSES WHOSE REAL USER ID EQUALS WHO, IF WHO IS 0 USE CALLER ID
 */

int main() {
    int which = PRIO_PROCESS; // OPERATE ON PROCESS
    int who = 0; // USE CALLER ID THAT IS SAME AS CALLING GETPID()
    id_t priority = getpriority(which, who);
    printf("Nice Value of the process is: %d\n", priority); // 0 IS THE DEFAULT ONE
    return 0;
}
