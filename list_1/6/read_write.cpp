#include<unistd.h>
#include<iostream>
#include<fcntl.h>
using namespace std;
int main(){
    int reader =0,writer = 1;
    char data[1024];
    int i = read(reader,&data,sizeof(data));
    cout<<"characters read: "<<i<<endl;
    write(writer, &data,i);
    cout<<endl<<"wrote using write system call"<<endl;
    return 0;
}
