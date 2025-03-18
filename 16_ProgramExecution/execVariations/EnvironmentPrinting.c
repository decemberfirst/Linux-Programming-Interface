#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
  char *first  =  getenv("PASSED_FROM_PARENT");
   char *second = getenv("PASSED_FROM_PARENT2");

    printf("PASSED_FROM_PARENT: %s\n", first);
    printf("PASSED_FROM_PARENT2: %s\n", second);
    return 0;
}
