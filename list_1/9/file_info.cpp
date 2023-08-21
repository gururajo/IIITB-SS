#include <sys/stat.h>  // Import for using `stat` system call
#include <unistd.h>    // Import for using `stat` system call
#include <iostream>     // Import for `printf` & `perror` function
#include<fcntl.h>
using namespace std;
int main(int argc, char **argv){
    struct stat statbuf;
    if(argc != 2) {
        cout<<"Wrong No of arguments given";
        return 0;
     }
    stat(argv[1], &statbuf);
    cout<<"st_dev: "<<statbuf.st_dev<<endl;
    cout<<"inode: "<<statbuf.st_ino<<endl;
    cout<<"No of hard links"<<statbuf.st_nlink<<endl;
    cout<<"In a similar way all members acan be acesed";
    return 0 ;
}
