/*Name : perfect_fam.cpp
Author : Gururaj Otageri
Description :
Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call)
Date: 2nd sept, 2023.
*/
#include<iostream>
#include<fcntl.h>
 #include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
using namespace std;
int main(){
    if(fork()){
        cout<<"oops pregnant again...\n";
        int lastborn;
        if(lastborn = fork()){
            sleep(10);
            cout<<"Delivery successfull.. its a girl\nwaiting for the lastborn to terminate\n";
            int waitstatus;
            waitpid(lastborn, &waitstatus,0);
            cout<<"lastborn no more!!\n";           
        }
        else{
            cout<<"i know i am an accident\n";
            sleep(20);
        }
    }
    else{
        cout<<"hehe i was planned \n";
        sleep(100);
    }
    return 0;
}

