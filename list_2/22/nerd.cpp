#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include<iostream>
#include <sys/select.h>
using namespace std;
int main(){
    int fd, retval;
    char buf[1024];
    fd_set rfds;
    struct timeval tv;

    fd = open("messenger",  O_RDONLY);
    cout<<fd<<endl;
    FD_ZERO(&rfds);
    FD_SET(fd, &rfds);
    // FD_SET(0, &rfds);
    /* Wait up to five seconds. */

    tv.tv_sec = 10;
    tv.tv_usec = 0;

    retval = select(1, &rfds, NULL, NULL, &tv);
    if (retval)
    {
        read(fd, buf, sizeof(buf));
        cout<<buf<<endl;
    }
    else
        printf("You didn't send any data for 10 seconds! :(\n");
    cout<<retval<<endl;
    return 0;
}