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
    cout<<"Typing..:Do you want to have gooooood time?\n\n";
    write(fd, "N:Do you want to have gooooood s*x?\n\n", sizeof( "N:Do you want to have gooooood s*x?\n\n"));
    sleep(3);
    read(fd2, buf, sizeof(buf));
    cout<<buf;
    sleep(3);
    cout<<"Typing..:Well come to my place!\n";
    write(fd, "N:Well come to my place!\n" , sizeof("N:Well come to my place!\n"));
    sleep(3);
    return 0;   
}
