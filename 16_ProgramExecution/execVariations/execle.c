#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main() {
    // l means you can pass arguments as a list
    // e means you can pass environment variables, as vector of strings
    char *env[] = {"PASSED_FROM_PARENT=foundyar", "PASSED_FROM_PARENT2=foundyar", '\0'};
    execle("./EnvironmentPrinting", "ROHAN", "-l", NULL, env); // THE SECOND ARGUMENT IS JUST  NAME OF THE PROGRAM, DOESNOT MATTER
    return 0;
}
