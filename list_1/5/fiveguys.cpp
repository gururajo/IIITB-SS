//Write a program to create five new files with infinite loop. Execute the program in the background
//and check the file descriptor table at /proc/pid/fd.
#include <iostream>
#include<fcntl.h>
using namespace std;
int main(){
    int fd[5]; 
    fd[0]  = open("stuff",O_RDWR|O_EXCL);
    fd[1]  = open("stuff",O_RDWR|O_EXCL);
    fd[3]  = open("stuff",O_RDWR|O_EXCL);
    fd[4]  = open("stuff",O_RDWR|O_EXCL);
    fd[5]  = open("stuff",O_RDWR|O_EXCL);
    while(1);
}
