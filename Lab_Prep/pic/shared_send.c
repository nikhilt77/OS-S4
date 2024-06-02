#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
int main(){
    char buffer[100];
    void *sh_memory;
    int id=shmget((key_t)1222,1024,0666|IPC_CREAT);
    sh_memory=shmat(id,NULL,0);

    printf("Segment attached at: %p\n",sh_memory);
    printf("Enter data:");
    read(0,buffer,100);
    strcpy(sh_memory,buffer);
    printf("Data entered is:%s\n",(char*)sh_memory);
    return(0);
}
