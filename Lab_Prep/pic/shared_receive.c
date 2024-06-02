#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
int main(){
    void *sh_memory;
    int id;
    id=shmget((key_t)1222,1024,0666);
    sh_memory=shmat(id,NULL,0);
    printf("Receiver attached to:%p\n",sh_memory);
    printf("Data of Receiver:%s\n",(char*)sh_memory);
    return(0);
}
