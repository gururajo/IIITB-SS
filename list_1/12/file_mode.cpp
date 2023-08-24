#include<iostream>
#include<fcntl.h>
#include<unistd.h>
using namespace std;
int main(){
    int reader, reader1;
    reader = open("somestuff", O_RDONLY);
//    cout<<reader<<endl;
    int ret = fcntl(reader,F_GETFL);
    cout<<ret<<endl;
    if(!(ret  & O_RDONLY))
    {   cout<<"behenchod\n";}
    else
        cout<<"shiiit\n";
    cout<<(ret  & O_RDWR);
   return 0;
}
