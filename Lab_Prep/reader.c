#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<unistd.h>
#include<sys/ipc.h>
#define SHM_SIZE 1024

int main(){
    int shmid;
    char *shm;
    key_t key=ftok("shmfile",'R');
    shmid=shmget(key,SHM_SIZE,0666);
    shm=shmat(shmid,NULL,0);
    printf("Writer Attached\n");
    printf("Message Shared:%s",shm);
    shmdt(shm);
}
