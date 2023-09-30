#include<iostream>
#include<fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
using namespace std;
int main(){
    int fd = open("shared.txt",O_CREAT|O_RDWR, 0666);
    int child;
    if(!(child = fork())){
      char buf[1024];
      int i;
      while(1){
        cout<<"Give the msg to parent..child here\n";
        do{
          cin>>buf;
          if(i){
            write(fd,buf,i);
          }
        }while(i>0);
      }
    }
    else{
        
    }
    return 0;
}
