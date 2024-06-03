#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define max 20
int mutex=1,full=0,empty=max,x=0;
void Producer(){
    --mutex;
    --empty;
    ++full;
    x++;
    printf("Producer produced P%d\n",x);
    ++mutex;
}
void Consumer(){
    --mutex;
    --full;
    printf("Consumed Process %d\n",x);
    x--;
    ++mutex;
    ++empty;
}
int main(){
    int n,ch;
    while(true){
        printf("1.Produce\n2.Consume\n3.Exit\n");
        printf("Enter choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:if(mutex==1&&empty!=0){
                    Producer();
                    }
                    else{
                    printf("Buffer Full\n");
                    }
                    break;
            case 2:if(mutex==1&&full!=0){
                    Consumer();
                    }
                    else{
                        printf("Buffer Empty\n");
                    }
                    break;
            case 3:exit(0);
        }
    }
}
