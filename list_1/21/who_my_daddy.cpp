#include<iostream>
#include<fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
using namespace std;
int main(){
    if(!fork()){    
    cout<<"child:  "<<getpid()<<endl;

    }    
else{
     cout<<"parent: "<<getpid()<<endl;
}
    return 0;
}
