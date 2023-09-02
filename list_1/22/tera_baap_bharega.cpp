/*Name : tera_baap_bharega.cpp
Author : Gururaj Otageri
Description :.Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file
Date: 2nd sept, 2023.
*/
#include<iostream>
#include<fcntl.h>
 #include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
using namespace std;
int main(){
    int fd  = open("bijli",O_WRONLY|O_CREAT, 0666);
    lseek(fd,0,SEEK_END);
    if(fork()){
        cout<<"Imma parent writing to file\n";
        write(fd, "Imma parent writing to file\n",sizeof("Imma parent writing to file\n"));
    }
    else{
        cout<<"Imma child writing to file\n";
        write(fd,"Imma child writing to file\n",sizeof("Imma child writing to file\n"));
    }
    return 0;
}

