#include<iostream>
#include<fcntl.h>
#include<unistd.h>
using namespace std;
int main(){
    int r, w ;
    struct flock rflock, wflock;
    r = open("stuff",O_RDWR|O_CREAT, 0666);
    cin>>w;
    rflock.l_type = F_RDLCK;
    rflock.l_whence = SEEK_SET;
    rflock.l_start = 0;
    rflock.l_len = 0;
    rflock.l_pid = getpid();
    cout<<rflock.l_pid<<endl;
    cout<<fcntl(r, F_GETLK, &rflock)<<endl;
    cout<<(rflock.l_type & F_UNLCK)<<"  "<<F_UNLCK<<endl;
    cout<<rflock.l_whence<<endl<<rflock.l_start<<endl<<rflock.l_len<<endl<<rflock.l_pid<<"\nsdfsdf\n";
    rflock.l_type = F_RDLCK;
    cout<< "Getting the lock\n";
    cout<<fcntl(r, F_SETLK, &rflock)<<endl;
    cout<<"GOT the lock\n";
    cout<<(rflock.l_type & F_RDLCK)<<"  "<<F_RDLCK<<"  "<<rflock.l_type<<endl;
    w = open("stuff",O_WRONLY);
    cout<<w<<endl;    
    char buf[1024]="soime stuff";
    cout<<write(w, buf, 11)<<endl;
    return 0;
}

