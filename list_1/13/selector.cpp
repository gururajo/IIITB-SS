
#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include <sys/select.h>
using namespace std;
int main(){
           fd_set rfds;
           struct timeval tv;
           int retval;

           /* Watch stdin (fd 0) to see when it has input. */

           FD_ZERO(&rfds);
           FD_SET(0, &rfds);

           /* Wait up to five seconds. */

           tv.tv_sec = 10;
           tv.tv_usec = 0;

           retval = select(1, &rfds, NULL, NULL, &tv);
           cout<<retval<<endl;
           if (retval) cout<<"Thank you for replying within 10secs";
            else cout<<"you missed the train fker";

   return 0;
    
}

