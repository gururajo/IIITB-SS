/*Name : orphanage.cpp
Author : Gururaj Otageri
Description :Write a program to create an orphan process.
Date: 2nd sept, 2023.
*/
#include<iostream>
#include<fcntl.h>
 #include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
using namespace std;
int main(){
    if(!fork()){
        cout<<"Imma child ,my parents left me :("<<getpid()<<endl;
        sleep(1000);
        cout<<"Thanks for teh donations\n";
    }
    else{
        cout<<"Imma ...;( i lost my child "<<getpid()<<endl;
        sleep(10);
        _exit(0);
    }
    return 0;
}

