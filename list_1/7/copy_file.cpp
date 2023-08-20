#include<unistd.h>
#include<iostream>
#include<fcntl.h>
using namespace std;
int main(int argc, char *argv[]){
    int reader, writer, i;
    char buf[1024];
    if(argc != 3) {
        cout<<"Wrong No of arguments provided"<<endl;return 0;
    }
    char *read_file = argv[1], *write_file = argv[2];
    reader  = open(read_file,O_RDONLY);
    writer = open(write_file,O_CREAT|O_WRONLY,00666);
    do{
        i = read(reader,&buf,sizeof(buf));
        if(i) write(writer, &buf, i);
}while(i);
}
