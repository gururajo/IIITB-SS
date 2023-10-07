#include <iostream>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <cstdlib> 
#include <cstdio>  
using namespace std;

int main()
{
    key_t semKey;
    int semIdentifier;
    int semctlStatus;

    union semun {
        int val; 
    } semSet;

    semKey = ftok(".", 1);

    semIdentifier = semget(semKey, 2, IPC_CREAT | 0777);
    semSet.val = 1; 

    semctlStatus = semctl(semIdentifier, 0, SETVAL, semSet);

    cout << "Semaphore created and initialized successfully!" << endl;

    return 0;
}
