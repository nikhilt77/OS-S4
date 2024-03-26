#include<stdio.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<sys/ipc.h>
#define SHM_SIZE 1024
int main(){
	char *ptr,*shm;
	int shmid;
	key_t key=ftok("shmfile",'A');
	shmid=shmget(key,SHM_SIZE,IPC_CREAT |0666);

	if (shmid < 0) {
        	perror("shmget");
        	exit(1);
        }

	shm=shmat(shmid,NULL,0);

	if (shm == (char *) -1) {
        	perror("shmat");
        	exit(1);
        }

	ptr=shm;
	printf("%s\n",ptr);
	shmdt(ptr);
	shmctl(shmid,IPC_RMID,NULL);
}
