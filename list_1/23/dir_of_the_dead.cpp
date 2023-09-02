/*Name : dir_of_the_dead.cpp
Author : Gururaj Otageri
Description :
Write a program to create a Zombie state of the running program
Date: 2nd sept, 2023.
*/
#include<iostream>
#include<fcntl.h>
 #include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
using namespace std;
int main(){
    if(fork()){
        cout<<"Imma parent ,I own this place\n";
        int s;
        cin>>s;
    }
    else{
        cout<<"Imma child \n";
    }
    return 0;
}

