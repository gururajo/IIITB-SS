#include <cstring>
#include <stdlib.h>
#include<iostream>
#include<fcntl.h>
#include<unistd.h>

using namespace std;
int main(){
    int w , max_tickets=200;
    struct flock rflock, wflock;

    w = open("tickets",O_RDWR);
	lseek(w,0,SEEK_SET);
	for(int i=0;i<3;i++){
		cout<<"Give the max tickets for "<<i<<" th train\n";
		cin>>max_tickets;
		write(w,&max_tickets,sizeof(int));
	}
	close(w);
	return 0;
}