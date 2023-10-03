#include<iostream>
#include<fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
using namespace std;
int main(){
    int ptc[2], ctp[2];
    if(pipe(ptc)==-1|| pipe(ctp)==-1){
        cout<<"Dint get the oppointment";
        return 0;
    }
    if(fork()){
        close(ptc[0]);
        write(ptc[1], "Pizza Delivery guy: knock knock...heres your pizza ma'am", sizeof("kPizza Delivery guy: nock knock...heres your pizza ma'am"));
        close(ctp[1]);
        char buf[1024];
        read(ctp[0], buf, sizeof(buf));
        cout<<buf<<endl;
        write(ptc[1], "Pizza Delivery guy: so.. if you didnt had cash with you,.... THEN WHY THE HELL DID YOU ORDER IT", sizeof("Pizza Delivery guy: so.. if you didnt had cash with you,.... THEN WHY THE HELL DID YOU ORDER IT"));

    }
    else{
        char buf[1025];
        close(ptc[1]);
        read(ptc[0], buf, sizeof(buf));
        cout<<buf<<endl;
        close(ctp[0]);
        write(ctp[1], "poor women: OOH NO,... i dont have cash one me right now.. \ndamn i was really craving it.. \n any other mode of payment (wink wink)", sizeof("poor women: OOH NO,... i dont have cash one me right now.. \ndamn i was really craving it.. \n any other mode of payment (wink wink)"));
         read(ptc[0], buf, sizeof(buf));
         cout<<buf<<endl;
    }

    return 0;
}

