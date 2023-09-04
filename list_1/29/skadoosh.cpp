#include<iostream>
#include<fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sched.h>
using namespace std;
int main(){
    int p_schd = sched_getscheduler(0);
    cout<<p_schd<<endl;
    cout<<SCHED_FIFO<<endl;
    cout<<SCHED_RR<<endl;
    cout<<SCHED_OTHER<<endl;
    struct sched_param priority;
    priority.sched_priority = 10;
    if(p_schd == SCHED_FIFO){
        cout<<"changed sched1:"<<sched_setscheduler(0,SCHED_RR, &priority);
    }
    else if(p_schd == SCHED_RR)
         cout<<"changed sched2:"<<sched_setscheduler(0,SCHED_FIFO, &priority);
    else
         cout<<"changed sched3:"<<sched_setscheduler(0,SCHED_RR, &priority);
    perror("some error");

    return 0;
}

