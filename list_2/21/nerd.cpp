#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include<iostream>
using namespace std;
int main(){
    int fd, fd2;
    char buf[1024];
    fd = open("messenger", O_WRONLY);
    fd2 = open("messenger2", O_RDONLY);
    while(1){
        cout<<"Typing..:1";
        cin>>buf;
        // cout<<buf<<endl;
        sleep(1);
        write(fd, buf , sizeof( strlen(buf)));
        read(fd2, buf, sizeof(buf));
        cout<<buf<<endl;
        sleep(1);
    }
    return 0;
}