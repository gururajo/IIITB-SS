#include <unistd.h>   
#include <sys/types.h>
#include <stdio.h>   

int main()
{
    int pipefd[2];  
    int pipeStatus;
    pid_t childPid;

    pipeStatus = pipe(pipefd);

        childPid = fork();

        if (childPid == 0)
        {
            close(STDIN_FILENO);
            dup(pipefd[0]); 
            close(pipefd[1]);
            execl("/usr/bin/wc", "wc", NULL);
        }
        else
        {

            close(STDOUT_FILENO);
            dup(pipefd[1]); 
            close(pipefd[0]);
            execl("/usr/bin/ls", "ls -l", "-l", NULL);
        }
    return 0;

}
