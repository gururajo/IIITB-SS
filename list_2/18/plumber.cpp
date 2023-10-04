#include <unistd.h>   
#include <sys/types.h>
#include <stdio.h>   
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int pipefd[2], pipefd2[2];

    pipe(pipefd);
    pipe(pipefd2);

    if (fork())
    {
        if(fork()){
            cout<<"starting the parent of all child";
            close(pipefd[1]);
            close(pipefd2[0]);
            close(pipefd2[1]);
            dup2(pipefd[0], 0);
            execl("/usr/bin/wc", "wc", NULL);
        }
        else{
            cout<<"string the mid child";
            close(pipefd[0]);
            dup2(pipefd[1], 1);
            close(pipefd2[1]);
            dup2(pipefd2[0], 0);
            execl("/usr/bin/grep", "grep ^d", "^d", NULL);
        }
    }
    else 
    {       cout<<"jasdhgfkjhsadf"<<STDOUT_FILENO<<endl;
            char buf[1025];
            getcwd(buf, sizeof(buf));
            cout<<"stating the childest child\n";
            cout<<buf<<endl;
            close(pipefd2[0]);
            close(pipefd[0]);
            close(pipefd[1]);
            
            dup2(pipefd2[1], 1);
            execl("/usr/bin/ls", "ls -l", "-l", NULL);
    }
    return 0;

}
