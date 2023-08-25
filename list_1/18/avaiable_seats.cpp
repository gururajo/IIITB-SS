#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include <cstring>
#include <stdlib.h>
using namespace std;
int main(){
    int r, max_tickets=200, tickets;
    struct flock rflock, wflock;

    r = open("tickets",O_RDONLY);
    if(r<0){
        cout<<"Not able to open tickets file";
        return 0;
    }
     rflock.l_type = F_RDLCK;
     rflock.l_whence = SEEK_SET;
     rflock.l_start = 0;
     rflock.l_len = 0;

    while(1){
      cout<<"Enter the train_id (1 or 2 or 3)\n";
      int trainid;
      cin>>trainid;
	  if(trainid>3 || trainid<1){
			cout<<"Give correct train id PLS\n";
			continue;
        }
      cout<<"Getting read lock \n";
		rflock.l_type = F_RDLCK;
		rflock.l_whence = SEEK_SET;
		rflock.l_start = (trainid-1) * sizeof(int);
		rflock.l_len = sizeof(int);
      fcntl(r, F_SETLKW, &rflock);
      cout<<"Got the read lock... reading\n";
      lseek(r,(trainid-1) * sizeof(int),SEEK_SET);
      read(r, &tickets, sizeof(int));
      cout<<"No of seats avaiable : "<<tickets<< endl;
       // cout<<"Sleeping for 10secs\n";
       // sleep(10);
        rflock.l_type = F_UNLCK;
        fcntl(r, F_SETLKW, &rflock);
    }
    return 0;
}

