#include<iostream>
#include<fcntl.h>
#include<unistd.h>
using namespace std;
int main(){
    int reader ,i;
    reader = open("somestuff",O_RDONLY);
    if(reader<0) return 0;
    char buf[1];
    string s;
    do{
        i = read(reader,&buf, 1);
        if(i && buf[0]!='\n')  s+=buf;
        else if(i && buf[0]=='\n'){ cout<<s<<endl; s="";}
      }while(i);
    close(reader);
    return 0;
}
