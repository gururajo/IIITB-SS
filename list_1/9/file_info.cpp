#include <sys/stat.h>  // Import for using `stat` system call
#include <unistd.h>    // Import for using `stat` system call
#include <iostream>     // Import for `printf` & `perror` function
#include<fcntl.h>
#include<time.h>
using namespace std;
int main(int argc, char **argv){
    struct stat file_stat;
    if(argc != 2) {
        cout<<"Wrong No of arguments given";
        return 0;
     }
    stat(argv[1], &file_stat);
    cout<<"st_dev: "<<file_stat.st_dev<<endl;
    cout<<"inode: "<<file_stat.st_ino<<endl;
    cout<<"No of hard links"<<file_stat.st_nlink<<endl;
    cout<<"timeee"<<file_stat.st_atim.tv_sec;
    cout<<"timeee"<<ctime(&file_stat.st_atim.tv_sec);
    cout<<"In a similar way all members acan be acesed";
    return 0 ;
}
