#include "../../include/apue.h"

int main(int argc, char* argv[])
{
    struct stat st_StatRet;
    char*       pc_Result;

    for(int i = 1; i < argc; i++)
    {
        printf("%s: ", argv[i]);
        if(lstat(argv[i], & st_StatRet) < 0)
        {
            err_ret("lstat error");
            continue;
        }
        if(S_ISREG(st_StatRet.st_mode))
            pc_Result = "regular";
        else if (S_ISDIR(st_StatRet.st_mode))
            pc_Result = "directory";
        else if (S_ISCHR(st_StatRet.st_mode))
            pc_Result = "character special";
        else if (S_ISBLK(st_StatRet.st_mode))
            pc_Result = "block special";
        else if (S_ISFIFO(st_StatRet.st_mode))
            pc_Result = "fifo";
        else if (S_ISLNK(st_StatRet.st_mode))
            pc_Result = "symbolic link";
        else if (S_ISSOCK(st_StatRet.st_mode))
            pc_Result = "socket";
        else
            pc_Result = "** unknown mode **";
            
        printf("%s\n", pc_Result);
    }
}