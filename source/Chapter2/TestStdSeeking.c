#include "../../include/apue.h"

int main(void)
{
    off_t currPos;
    currPos = lseek(STDIN_FILENO, 0, SEEK_CUR); 
    if( currPos == -1)
    {
        printf("cannot seek\n");
    }
    else
    {
        printf("seek OK! Current file offset is: %ld\n", currPos);
    }
    exit(0);
}