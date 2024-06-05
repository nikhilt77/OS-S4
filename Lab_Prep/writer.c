#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#define SHM_SIZE 1024

int main(){
    int shmid;
    char *word;
    char *shm;
    key_t key=ftok("shmfile",'R');
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    shm=shmat(shmid,NULL,0);
    char str[100];
    printf("Enter data:");
    scanf("%s",str);
    strcpy(shm,str);
    printf("Data Wrote\n");
    shmdt(shm);
}
