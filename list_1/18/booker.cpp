#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include <cstring>
#include <stdlib.h>
using namespace std;
int main(){
    int w , max_tickets=200;
    struct flock rflock, wflock;

    w = open("tickets",O_RDWR);
    if(w<0){
        cout<<"Not able to open tickets file";
        return 0;
    }
    //cout<<"Give the max tickets\n";
    //cin>>max_tickets;
    //write(w,&max_tickets,sizeof(int));
    rflock.l_type = F_WRLCK;
    rflock.l_whence = SEEK_SET;
    rflock.l_start = 0;
    rflock.l_len = 0;
    
	  while(1){
        cout<<"Give the train number (1 or 2 or 3)\n";
        int trainid;
        cin>>trainid;
        if(trainid>3 || trainid<1){
                cout<<"Give correct train id PLS\n";
                continue;
        }
      	cout<< "Give the no of tickets to book\n";
      	int t;
      	cin>>t;
      	cout<<"getting lock\n";
      	rflock.l_type = F_WRLCK;
		rflock.l_whence = SEEK_SET;
		rflock.l_start = (trainid-1) * sizeof(int);
		rflock.l_len = sizeof(int);
		fcntl(w, F_SETLKW, &rflock);
		cout<<"Got the lock "<<(rflock.l_type==F_WRLCK)<<endl;      	
      	lseek(w,(trainid-1) * sizeof(int),SEEK_SET);
      	int tickets;
      	int i= read(w,&tickets,sizeof(tickets));
        cout<<tickets<<" No of tickets available	\n";
      	tickets-=t;
      	if (tickets>0){
      		cout<<"successfully booked\n";
      	}else{
      		cout<<"not enough tickets availble\n";
      		tickets+=t;
      	}
      	lseek(w,(trainid-1) * sizeof(int),SEEK_SET);
      	write(w, &tickets, sizeof(tickets));
      	cout<<"sleeping for 10 secs\n";
      	sleep(10);
      	cout<<"unlocking \n";
        rflock.l_type = F_UNLCK;
      	fcntl(w, F_SETLKW, &rflock);
   }
    int tickets;
    lseek(w,0,SEEK_SET);
    read(w, &tickets, sizeof(int));
    cout<<"After updating "<<tickets;
    return 0;
}

