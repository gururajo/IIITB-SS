#include<iostream>
#include<fcntl.h>
#include<unistd.h>
using namespace std;
int main(){
    int reader ,i;
    reader = open("somestuff",O_RDONLY);
    if(reader<0) return 0;
    char buf[1];
    do{
        i = read(reader,&buf, 1);
        if(i)  cout<<buf;
      }while(i);
    close(reader);
    return 0;
}
