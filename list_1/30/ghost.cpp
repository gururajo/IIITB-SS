/*Name : ghost.cpp
Author : Gururaj Otageri
Description :
     Write a program to run a script at a specific time using a Daemon process.
Date: 2nd sept, 2023.
*/
include<iostream>
#include<fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
       #include <sys/stat.h>
#include<string.h>
using namespace std;
int main(){
    if(!fork()){
        sleep(1);
        setsid();
        umask(0);
        int fd = open("loggg",O_WRONLY|O_CREAT,0666),c=0;
        char a[1024];
        cout<<"Demon created\n";
        time_t now, then;
        time(&now);
        cout<<now;
        struct tm *when;
        when  = localtime(&now);
        when->tm_hour = 16;
        when->tm_min = 0;
        when->tm_sec = 0;
        then = mktime(when);
        cout<<"\nsdleeping :"<<then-now<<endl;
        sleep(then-now);
        while(1){
            time(&now);
            sprintf(a,"wassup?:%ld\n",now);
            write(fd, a,strlen(a));
            cout<<"wrote "<<c<<endl;
            c++;
            sleep(86400);
        }
    
    }
    return 0;
}

