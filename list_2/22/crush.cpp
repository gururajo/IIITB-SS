#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include<iostream>
using namespace std;
int main(){
    int fd, fd2;
    char buf[1024]="something";
    fd = open("messenger", O_WRONLY);
    
    write(fd, buf , sizeof( strlen(buf)));
    return 0;
}