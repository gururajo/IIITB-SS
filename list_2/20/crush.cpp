#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<iostream>
using namespace std;
int main(){
    int fd, fd2;
    char buf[1024];
    fd = open("messenger", O_RDWR);
    fd2 = open("messenger2", O_RDWR);
    read(fd, buf, sizeof(buf));
    cout<<buf;
    sleep(3);
    cout<<"Typing..:Uhmm.. sorry, no?\n\n";
    write(fd2, "C: -Uhmm.. sorry, no?\n\n" , sizeof( "C: -Uhmm.. sorry, no?\n\n"));
    sleep(3);
     read(fd, buf, sizeof(buf));
    cout<<buf;
    sleep(3);
    return 0;
}