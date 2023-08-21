#include <sys/stat.h>  // Import for using `stat` system call
#include <unistd.h>    // Import for using `stat` system call
#include <iostream>     // Import for `printf` & `perror` function
#include<fcntl.h>

using namespace std;
int main(int argc, char **argv){
    int rdwr;
    rdwr = open("somestuff",O_RDWR|O_CREAT,0666);
    if(rdwr<0){
        cout<<"ERROR opening file";
        return 0;
    }
    write(rdwr,"just writing some stuff",sizeof("just writing some stuff"));
    cout<<lseek(rdwr, -10, SEEK_CUR);
    write(rdwr, "this is new stuff",sizeof("this is new stuff"));
    int reader,i, c=0;
    reader = open("somestuff",O_RDONLY);
    if(reader<0) {
        cout<<"ERROR reading files";
        return 0;
    }
    char buf[1024];
    do{
        i=read(reader, &buf, size(buf));
        int j;
        for(j=0;j<i;j++)
            if(buf[j]==' ')
                c++;
        }while(i);
    cout<<"No of spaces ==  = "<<c;
    return 0 ;
}
