#include "../../include/apue.h"
#include <dirent.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;
    
    switch (argc)
    {
    case 1:
        if((dp = opendir("./")) == NULL)
        {
            err_sys("can't open cuurent directory");
        }
        break;
    case 2:
        if((dp = opendir(argv[1])) == NULL)
        {
            err_sys("can’t open %s", argv[1]);
        }
        break;
    default:
        err_quit("usage: ls directory_name");
        break;
    }

    while ((dirp = readdir(dp)) != NULL)
    {
        printf("%s\n", dirp->d_name);
    }
    closedir(dp);
    
    exit(0);
}