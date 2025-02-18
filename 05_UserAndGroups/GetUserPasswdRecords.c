#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>

int main()
{
    struct passwd *UserPasswdInfo;
    UserPasswdInfo = getpwnam("rohan");
    if (UserPasswdInfo == NULL)
    {
        printf("Didnot find any user with that user name: \n");
        exit(1);
    }

    printf("The user name is : %s\n", UserPasswdInfo->pw_name);
    printf("The user password is : %s\n", UserPasswdInfo->pw_passwd);
    printf("The userID is: %d\n", UserPasswdInfo->pw_uid);
    printf("The user group id is: %d \n", UserPasswdInfo->pw_gid);
    printf("The user shell is : %s\n", UserPasswdInfo->pw_shell);
    printf("The user home directory is: %s \n", UserPasswdInfo->pw_dir);
    return 0;
}
