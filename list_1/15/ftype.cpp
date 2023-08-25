#include<iostream>
#include<fcntl.h>
#include <sys/stat.h>
#include<unistd.h>
using namespace std;
int main(int argc, char **argv ){
    for(int i=0;i<40;i++)
    cout<<i<<" "<<environ[i]<<endl;
   return 0;
}

