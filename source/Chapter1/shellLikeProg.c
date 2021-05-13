#include "../../include/apue.h"
#include <sys/wait.h>

int main(void)
{
    char buf[MAXLINE]; /*from apue.h*/
    pid_t pid;
    int status;

    printf("%% "); // print prompt
    while (fgets(buf, MAXLINE, stdin) != NULL)
    {
        if (buf[strlen(buf) - 1] == '\n')
        {
            buf[strlen(buf) - 1] = 0;
        }

        //create new proocess
        pid = fork();

        if (pid < 0)
        {
            err_sys("fork error");
        }
        else if (pid == 0)
        {
            // child 
            execlp(buf, buf, (char*)0);
            err_ret("could'n excecute :%s", buf);
            exit(127);
        }

        // parrent
        if ((pid = waitpid(pid, &status, 0)) < 0)
        {
            err_sys("waitpid error");
        }
        printf("%% ");        
    }
    exit(0);
}