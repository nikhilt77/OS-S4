#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
#define max 20
int Buffer[max];
sem_t full;
sem_t empty;
sem_t mutex;
int in=0,out=0;
void *Producer(void *arg){
    while(1){
    int item;
    item=rand()%max;
    sem_wait(&mutex);
    sem_wait(&empty);
    Buffer[in]=item;
    printf("Producer produced %d at index %d\n",item,in);
    in=(in+1)%max;
    sem_post(&mutex);
    sem_post(&full);
    sleep(1);
    }

}
void *Consumer(void *arg){
    while(1){
    int item;
    sem_wait(&mutex);
    sem_wait(&full);
    item=Buffer[out];
    printf("Consumer consumed %d\n",item);
    out=(out+1)%max;
    sem_post(&mutex);
    sem_post(&empty);
    sleep(1);
    }

}
int main(){
   pthread_t producer,consumer;
   sem_init(&mutex,0,1);
   sem_init(&full,0,0);
   sem_init(&empty,0,max);

   pthread_create(&producer,NULL,Producer,NULL);
   pthread_create(&consumer,NULL,Consumer,NULL);

   pthread_join(producer,NULL);
   pthread_join(consumer,NULL);

   sem_destroy(&empty);
   sem_destroy(&mutex);
   sem_destroy(&full);
   return 0;
}
