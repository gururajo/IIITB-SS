#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<iostream>
using namespace std;
int main(){
    int fd;
    fd = mknod("stack", 0777|S_IFIFO, 0);
    cout<<fd;

}