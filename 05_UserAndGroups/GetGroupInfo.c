#include <stdio.h>
#include <grp.h>

int main()
{
    struct group *UserGroupInfo;
    UserGroupInfo = getgrnam("postgres");
    printf("The  group name is : %s \n", UserGroupInfo->gr_name);
    printf("The  group id is : %d \n", UserGroupInfo->gr_gid);
    return 0;
}
