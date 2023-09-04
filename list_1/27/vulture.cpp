/*Name : vulture.cpp
Author : Gururaj Otageri
Description :
Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execled. execv
e. execvp
Date: 2nd sept, 2023.
*/
#include<iostream>
#include<fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
using namespace std;
int main(){
    //execl("/usr/bin/ls","dummy", "-l",NULL);
    cout<<"this never runs if its succefull\n";
    //execlp("ls","dummy", "-l",NULL);
    //giving 2nd argument dummy, but should be given a exe filename... its just a showcase that that is not used
    //execle("/usr/bin/ls","dummy", "-l",NULL,NULL);
    char* argv[]={"ls","-l",NULL};
    //execv("/usr/bin/ls",argv);
    execvp("ls",argv);
    return 0;
}

