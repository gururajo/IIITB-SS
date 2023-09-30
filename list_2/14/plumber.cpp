#include<iostream>
#include<fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
using namespace std;
int main(){
    int pipes[2];
    if(pipe(pipes)!=-1){
       write(pipes[1],"reparing pipe",sizeof("reparing pipe"));
        char buf[1024];
       read(pipes[0],buf,sizeof(buf));
        cout<<"plumber: "<<buf<<endl;
    }
    return 0;
}

