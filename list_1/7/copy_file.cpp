#include<unistd.h>
#include<iostream>
#include<fcntl.h>
using namespace std;
int main(){
    int reader, writer, i;
    char buf[1024];
    reader  = open("somestuff",O_RDONLY);
    writer = open("copiedstuff",O_CREAT|O_WRONLY,666);
    do{
        i = read(reader,&buf,sizeof(buf));
        if(i) write(writer, &buf, i);
}while(i);
}
