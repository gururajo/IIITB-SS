#include<iostream>
#include<fcntl.h>
using namespace std;
int main(){
   int fd;
cout<<O_RDWR<<"   "<<O_EXCL<<endl;
   fd  = open("stuff",O_RDWR|O_EXCL);
   cout<<fd;
return 0;
}

