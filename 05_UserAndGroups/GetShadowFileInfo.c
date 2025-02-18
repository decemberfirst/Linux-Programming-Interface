#include <stdio.h>
#include <shadow.h>
#include <stdlib.h>

int main()
{
    struct spwd *UserShadow = getspnam("rohan");

    if (UserShadow == NULL)
    {
        perror("Error retrieving shadow entry");
        return 1;
    }

    printf("The password hash for user 'rohan' is: %s\n", UserShadow->sp_pwdp);

    return 0;
}
