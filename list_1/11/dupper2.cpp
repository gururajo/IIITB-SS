#include<iostream>
#include<fcntl.h>
#include<unistd.h>
using namespace std;
int main(){
    int reader, reader1;
    reader = open("somestuff", O_RDWR); 
    reader1 = dup2(reader, 5);
    cout<<reader1<<endl;
    if(reader<0 ) {
        cout<<"not able to open file";
        return 0;
     }
    char buf[1024];
    int i=    read(reader,&buf,sizeof(buf));
    write(reader,buf,i);
    write(reader1,buf,i);

   return 0;
}
