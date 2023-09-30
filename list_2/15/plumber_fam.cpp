#include<iostream>
#include<fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
using namespace std;
int main(){
    int pipes[2];
    if(pipe(pipes)==-1){
        cout<<"Dint get the oppointment";
        return 0;
    }
    if(fork()){
        close(pipes[0]);
        write(pipes[1], "Beta plumber ko paisa leke aao", sizeof("Beta plumber ko paisa leke aao"));
    }
    else{
        char buf[1025];
        close(pipes[1]);
        read(pipes[0], buf, sizeof(buf));
        cout<<buf<<endl;
    }

    return 0;
}

