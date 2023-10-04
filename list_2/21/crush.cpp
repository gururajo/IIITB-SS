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
    fd = open("messenger", O_RDONLY);
    fd2 = open("messenger2", O_WRONLY);
    while(1){
        read(fd, buf, sizeof(buf));
        cout<<buf<<endl;
        sleep(1);
        cout<<"Typing..:";
        cin>>buf;
        sleep(1);
        write(fd2, buf , sizeof( strlen(buf)));
    }
    return 0;
}