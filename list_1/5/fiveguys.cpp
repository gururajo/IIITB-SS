//Write a program to create five new files with infinite loop. Execute the program in the background
//and check the file descriptor table at /proc/pid/fd.
#include <iostream>
#include<fcntl.h>
using namespace std;
int main(){
    int fd[5]; 
    fd[0]  = open("stuff",O_RDWR| O_CREAT, 0666);
    fd[1]  = open("stuff",O_RDWR);
    fd[3]  = open("stuff",O_RDWR);
    fd[4]  = open("stuff",O_RDWR);
    fd[2]  = open("stuff",O_RDWR);
    cout<<"created all"<<endl;
    for(int i=0;i<5;i++)
        cout<<fd[i]<<"  ,";
    while(1);
//int i;cin>>i;
}
