#include <stdlib.h>
#include <sys/stat.h>  // Import for using `stat` system call
#include <unistd.h>    // Import for using `stat` system call
#include <iostream>     // Import for `printf` & `perror` function
#include<fcntl.h>
#include <cstdlib>
#include<string>
using namespace std;
int main(int argc, char **argv){
    int reader1,reader2,i, c=0;
    reader1 = open("somestuff",O_RDONLY);
    if(reader1<0) {
        cout<<"ERROR reading files";
        return 0;
    }
    reader2 = dup(reader1);
    lseek(reader1,0,SEEK_END);
    lseek(reader2,0,SEEK_END);
    char buf[1024] = "1  somestuff ";
    //itoa(reader1,&buf, 10) ;
    cout<<buf<<endl;   
    write(reader1,buf, sizeof(buf));
    buf[0] = '2';
    write(reader2,buf, sizeof(buf));
    return 0 ;
}
