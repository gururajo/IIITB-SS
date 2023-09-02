#include<iostream>
#include<fcntl.h>
 #include <unistd.h>
#include <sys/time.h>
       #include <sys/resource.h>
using namespace std;
int main(){
    int mpid= getpid();
    cout<<mpid<<endl;
    cout<<getpriority(PRIO_PROCESS, mpid)<<endl;
    cout<<nice(-4)<<endl;
    cout<<getpriority(PRIO_PROCESS, mpid)<<endl;
    int s;
    cin>>s;
    cout<<setpriority(PRIO_PROCESS, mpid, 16)<<endl;
    cout<<getpriority(PRIO_PROCESS, mpid)<<endl;
    cin>>s;
    return 0;
}

