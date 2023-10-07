#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include<iostream>
#include <sys/select.h>
using namespace std;
int main(){
    cout<<sysconf(_SC_OPEN_MAX)<<endl;
    cout<<pathconf("messenger", _PC_PIPE_BUF);

    return 0;
}