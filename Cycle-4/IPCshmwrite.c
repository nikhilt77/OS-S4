#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#define SHM_SIZE 1024

int main(){
	int shmid;
	char *ptr,*shm;
	key_t key=ftok("shmfile",'A');
	shmid=shmget(key,SHM_SIZE,IPC_CREAT |0666);
	shm=shmat(shmid,NULL,0);
	ptr=shm;
	scanf("%s",ptr);
	printf("Data Wrote\n");
}
